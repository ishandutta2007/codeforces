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
#define N 100005
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int num[N],vis[N];
int main()
{
    int n,k,a,b,c,d,i;
    cin>>n>>k;
    if(n==4||k<n+1)
    {
        printf("-1\n");
        return 0;
    }
    cin>>a>>b>>c>>d;
    vis[a]=vis[b]=vis[c]=vis[d]=1;
    printf("%d %d ",a,c);
    for(i=1;i<=n;i++)
        if(!vis[i])
        {
            //num[++cnt]=i;
            printf("%d ",i);
        }
    printf("%d %d\n",d,b);

    printf("%d %d ",c,a);
    for(i=1;i<=n;i++)
        if(!vis[i])
        {
            //num[++cnt]=i;
            printf("%d ",i);
        }
    printf("%d %d\n",b,d);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")  //compiler vc++
//#define O2 __attribute__((optimize("-O2")))