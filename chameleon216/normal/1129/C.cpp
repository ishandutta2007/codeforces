#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=3100,Mod=1000000007;
int N;
int S[MX],sc,dp[MX],ans;

const int HashMod=2718281;
struct HashTable{ll v;int nx;}E[5000000];
int H[HashMod],ec;
bool Ins(ll v)
{
	int x=v%HashMod;
	for(int i=H[x];i;i=E[i].nx)
		if(E[i].v==v)return 0;
	E[++ec].v=v,E[ec].nx=H[x],H[x]=ec;
	return 1;
}

const int Base=131,P=1000000123,Q=1000000321;

void Append(int x)
{
	S[++sc]=x;
	dp[sc+1]=1;
	ll a=0,b=0;
	Fl(i,sc,1)
	{
		int s=S[i]<<3|S[i+1]<<2|S[i+2]<<1|S[i+3];
		int u=3+(s!=3&&s!=5&&s!=14&&s!=15);
		dp[i]=0;
		Fr(j,1,u)dp[i]=(dp[i]+dp[i+j])%Mod;
		
		a=(a*Base+S[i]+1)%P;
		b=(b*Base+S[i]+1)%Q;
		if(Ins(a<<32|b))ans=(ans+dp[i])%Mod;
	}
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int x;
		scanf("%d",&x);
		Append(x);
		printf("%d\n",ans);
	}
	return 0;
}