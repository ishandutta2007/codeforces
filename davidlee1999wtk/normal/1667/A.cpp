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
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int a[N];
LL b[N];
int main()
{
    int n, i, j;
    LL ans = LL(INF) * INF;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=1;i<=n;i++)
    {
        LL now = 0;
        for(j=1;j<=n;j++)
            b[j] = 0;
        for(j=i-1;j;j--)
        {
            now += b[j+1] / a[j] + 1;
            b[j] = (b[j+1] / a[j] + 1) * a[j];
        }
        for(j=i+1;j<=n;j++)
        {
            now += b[j-1] / a[j] + 1;
            b[j] = (b[j-1] / a[j] + 1) * a[j];
            //debug(b[j]);
        }
        ans = min(ans, now);
    }
    cout<<ans<<endl;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);