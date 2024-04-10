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
#define N 100005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> G[N];
int u[N],v[N],rd[N];
int main()
{
    int i,n,m,l,r,mid,ans=-1,x,y;
    cin>>n>>m;
    l=1,r=m;
    for(i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    while(l<=r)
    {
        mid=(l+r)>>1;
        //debug(mid);
        for(i=1;i<=n;i++)
            G[i].clear();
        memset(rd,0,sizeof(rd));
        for(i=1;i<=mid;i++)
            G[u[i]].push_back(v[i]),rd[v[i]]++;
        queue<int> q;
        for(i=1;i<=n;i++)
            if(rd[i]==0)
                q.push(i);
        while(!q.empty()&&q.size()<2)
        {
            x=q.front(),q.pop();
            //debug(x);
            for(i=0;i<G[x].size();i++)
            {
                y=G[x][i];
                rd[y]--;
                //debug(y);
                if(rd[y]==0)
                    q.push(y);
            }
        }
        if(q.empty())
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))