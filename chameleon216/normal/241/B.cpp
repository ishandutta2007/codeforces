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

const int MX=50100,W=30,Mod=1000000007;

ll Pow(ll a,ll p)
{
	ll r=1;
	a%=Mod;
	while(p)
	{
		if(p&1)r=r*a%Mod;
		a=a*a%Mod,p>>=1;
	}
	return r%Mod;
}
ll Inv(ll a){return Pow(a,Mod-2);}

int N,A[MX];
ll K;
int S[MX][W];

struct O1Trie{int v,l,c[2];}T[MX<<5];
int tc=1;
void Ins(int n)
{
	int i=1;
	Fl(j,W-1,0)
	{
		++T[i].v;
		int &p=T[i].c[A[n]>>j&1];
		if(!p)p=++tc,T[p].l=n;
		i=p;
	}
	++T[i].v;
}

ll AskT(int i,int x) // a[i]^x 
{
	if(!i)return 0;
	int l=T[i].l,r=l+T[i].v-1;
	ll sum=0;
	Fo(w,0,W)
	{
		ll t=S[r][w]-S[l-1][w];
		sum+=(x>>w&1?T[i].v-t:t)<<w;
	}
	return sum;
}

int J[MX];
ll Sum2(ll k) //k
{
	ll ans=0;
	int x=0;
	Fr(i,1,N)J[i]=1;
	Fl(w,W-1,0)
	{
		ll v=0;
		Fr(i,1,N)v+=T[T[J[i]].c[(A[i]>>w&1)^1]].v;
		int o=k<=v;
		if(o)x|=1<<w;
		else
		{
			k-=v;
			Fr(i,1,N)ans+=AskT(T[J[i]].c[(A[i]>>w&1)^1],A[i]),ans%=Mod;
		}
		Fr(i,1,N)J[i]=T[J[i]].c[(A[i]>>w&1)^o];
	}
	ans+=k*x,ans%=Mod;
	return ans;
}


int main()
{
	IO>>N>>K;
	Fr(i,1,N)IO>>A[i];
	sort(A+1,A+N+1);
	
	Fr(i,1,N)Fo(j,0,W)
		S[i][j]=S[i-1][j]+(A[i]>>j&1);
	
	T[1].l=1;
	Fr(i,1,N)Ins(i);
	printf("%lld\n",Sum2(K*2)*Inv(2)%Mod);
	
	return 0;
}