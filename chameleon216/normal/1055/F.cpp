#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MX=1000100;
int N;
ll K;
ll A[MX];

const int W=61;
struct O1Trie{int v,c[2];}T[MX],U[MX];
int I[MX],J[MX]; //  /  **  

ll Kth2(ll k)
{
	O1Trie *t=T,*u=U; // ()
	Fr(i,1,N)I[i]=J[i]=1;
	t[1].v=N;
	ll res=0;
	Fl(j,W,0) //01-Trie
	{
		memset(u,0,(N+1)*sizeof(O1Trie));
		int c=0;
		Fr(i,1,N) //Trie
		{
			int &a=t[I[i]].c[A[i]>>j&1];
			if(!a)a=++c;
			++u[a].v;
		}
		ll v=0;
		Fr(i,1,N)v+=u[t[J[i]].c[A[i]>>j&1]].v; //
		if(k>v)res|=1ll<<j,k-=v;
		Fr(i,1,N) //
		{
			I[i]=t[I[i]].c[A[i]>>j&1];
			J[i]=t[J[i]].c[(A[i]^res)>>j&1];
		}
		swap(t,u);
	}
	return res;
}

int main()
{
	IO>>N>>K;
	Fr(i,2,N)
	{
		int f;
		ll x;
		IO>>f>>x;
		A[i]=A[f]^x;
	}
	printf("%lld\n",Kth2(K));
	return 0;
}