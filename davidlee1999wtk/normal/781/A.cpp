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
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int du[N],col[N];
vector<int> G[N];
void dfs(int x,int cf)
{
    int i,j=1,v;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
        if(!col[v])
        {
            for(;;j++)
                if(j!=col[x]&&j!=cf)
                {
                    col[v]=j;
                    j++;
                    break;
                }
            dfs(v,col[x]);
        }
    }
}

int main()
{
    int i,n,a,b,ans=0;
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        du[a]++,du[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=1;i<=n;i++)
        ans=max(ans,du[i]+1);
    col[1]=1;
    dfs(1,0);
    cout<<ans<<endl;
    for(i=1;i<=n;i++)
        printf("%d ",col[i]);
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/