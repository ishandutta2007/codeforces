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
#define INF 1000000000
#define N 5005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int c[N],ans[N];
int vis[N];
int main()
{
    int n,i,j,now_c,cnt;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        now_c=0,cnt=0;
        for(j=i;j<=n;j++)
        {
            vis[c[j]]++;
            if(vis[c[j]]>cnt)
                now_c=c[j],cnt++;
            else if(vis[c[j]]==cnt)
                if(c[j]<now_c)
                    now_c=c[j];
            ans[now_c]++;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))