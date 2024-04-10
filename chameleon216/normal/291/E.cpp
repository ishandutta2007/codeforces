#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=300100,W=300000;
int N,M;
char S_[MX],T[MX];
string S[MX];
ll Ht;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

namespace H_
{
	const int B=131,P=1000000123,Q=1000000321;
	
	ll Hash(char* s,int n)
	{
		ll a=0,b=0;
		Fr(i,1,n)
		{
			a=(a*B+s[i])%P;
			b=(b*B+s[i])%Q;
		}
		return a<<32|b;
	}
	
	ll a[MX],b[MX];
	ll g[MX],h[MX];
	int tp;
	
	void Init()
	{
		a[0]=b[0]=1;
		Fr(i,1,W)
		{
			a[i]=a[i-1]*B%P;
			b[i]=b[i-1]*B%Q;
		}
	}
	
	bool Push(char c)
	{
		++tp;
		g[tp]=(g[tp-1]*B+c)%P;
		h[tp]=(h[tp-1]*B+c)%Q;
		if(tp<M)return 0;
		ll p=(g[tp]-g[tp-M]*a[M]%P+P)%P;
		ll q=(h[tp]-h[tp-M]*b[M]%Q+Q)%Q;
		return (p<<32|q)==Ht;
	}
	
	void Pop(int n){tp-=n;}
}
using H_::Hash;
using H_::Init;
using H_::Push;
using H_::Pop;

int sum=0;
void dfs1(int x,int c)
{
	int z=S[x].size();
	Fo(i,0,z)if(Push(S[x][i]))
		++sum,++c;
	Fe(i,x,y)dfs1(y,c);
	Pop(z);
}

int main()
{
	scanf("%d",&N);
	Fr(x,2,N)
	{
		int f;
		scanf("%d%s",&f,S_);
		Link(f,x),S[x]=S_;
	}
	scanf("%s",T+1),M=strlen(T+1);
	Ht=Hash(T,M);
	Init();
//	printf("%lld\n",Ht);
	dfs1(1,0);
	printf("%d\n",sum);
	return 0;
}