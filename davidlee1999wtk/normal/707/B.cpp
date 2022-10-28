#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<bitset>
#include<ctime>
#include<deque>
#define N 100005
#define P 1000000007
#define INF 1000000000
#define fi first
#define se second
#define debug(x) cerr<<#x<<' '<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
bool vis[N];
int a[N],b[N],c[N];
int main()
{
    int n,m,k,x,ans=-1,i;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        vis[x]=1;
    }
    for(i=1;i<=m;i++)
        if(vis[a[i]]^vis[b[i]]==1)
            if(ans==-1)
                ans=c[i];
            else ans=min(ans,c[i]);
    cout<<ans<<endl;
    return 0;
}