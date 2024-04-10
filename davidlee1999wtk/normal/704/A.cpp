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
#define N 300005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int now[N],p=1,num[N],vis[N];
vector<int> app[N];
int main()
{
    int n,q,op,x,m=0,ans=0,i,j;
    cin>>n>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            m++;
            ans++;
            scanf("%d",&x);
            app[x].push_back(m);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            for(j=now[x];j<app[x].size();j++)
            {
                if(!vis[app[x][j]])
                    vis[app[x][j]]=1,ans--;
            }
            now[x]=app[x].size();
        }
        else
        {
            scanf("%d",&x);
            for(j=p;j<=x;j++)
                if(!vis[j])
                    vis[j]=1,ans--;
            p=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++