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
#define INF 1000000000
#define N 130005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> G[N];
int hm[N],dp[N],rt,ans=0,far[N],farp[N],ans2,ans3;
void dfs(int x,int fa)
{
    int i,v,len=G[x].size();
    if(hm[x])
        ans++,far[x]=dp[x],farp[x]=x;
    for(i=0;i<len;i++)
    {
        v=G[x][i];
        if(v!=fa)
        {
            dp[v]=dp[x]+1;
            dfs(v,x);
            if(hm[v])
            {
                if(!hm[x])
                    hm[x]=1,ans++;
                if(ans2==far[x]+far[v]-dp[x]*2)
                    ans3=min(ans3,min(farp[x],farp[v]));
                if(ans2<far[x]+far[v]-dp[x]*2)
                    ans2=far[x]+far[v]-dp[x]*2,ans3=min(farp[x],farp[v]);
                if(far[x]==far[v])
                    farp[x]=min(farp[x],farp[v]);
                if(far[x]<far[v])
                    farp[x]=farp[v],far[x]=far[v];
            }
        }
    }
}

int main()
{
    int a,b,n,i,m;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        hm[a]=1;
    }
    rt=a;
    dp[rt]=0;
    dfs(rt,0);
    if(ans==1)
        printf("%d\n%d\n",rt,0);
    else
        cout<<ans3<<endl<<ans*2-2-ans2<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))