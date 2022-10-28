#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 100000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}

LL dp[N],rel[N],r1[N],f[N];
int fa[N];
vector<int> G[N];
void dfs1(int x)
{
	int i,v;
	dp[x]=1;
	f[x]=1;
	for(i=0;i<G[x].size();i++)
	{
		v=G[x][i];
		dfs1(v);
		if(dp[v]+1!=P||dp[x]==0)
			f[x]=f[x]*(dp[v]+1)%P;
		dp[x]=dp[x]*(dp[v]+1)%P;
	}
}

void dfs2(int x)
{
	int i,v;
	LL t;
	for(i=0;i<G[x].size();i++)
	{
		v=G[x][i];
		if(dp[v]+1==P)
			t=r1[x];
		else
			t=ksm(dp[v]+1,P-2)*rel[x]%P;
		rel[v]=dp[v]*(t+1)%P;
		r1[v]=f[v]*(t+1)%P;
		dfs2(v);
	}
}

int main()
{
	int n,i;
	cin>>n;
	for(i=2;i<=n;i++)
		scanf("%d",&fa[i]),G[fa[i]].push_back(i);
	dfs1(1);
	rel[1]=dp[1];
	r1[1]=f[1];
	dfs2(1);
	for(i=1;i<=n;i++)
		printf("%I64d ",rel[i]);
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")