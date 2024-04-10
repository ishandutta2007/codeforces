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
#define N 300005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int h[N], b[N], q[N];
LL dp[N], max_dp[N];
int main()
{
    int n, i, j, tail=0;
    cin >> n;
    for(i=1;i<=n;i++)
        scanf("%d", &h[i]);
    for(i=1;i<=n;i++)
        scanf("%d", &b[i]);
    dp[0]=0;
    max_dp[0]=0;
    q[tail]=0;
    for(i=1;i<=n;i++)
    {
        LL now = (LL(-INF))*INF;
        while(h[i]<h[q[tail]])
        {
            now = max(now, max_dp[q[tail]]);
            tail--;
        }
        max_dp[q[tail]] = max(max_dp[q[tail]], now);
        if(q[tail]==0)
            max_dp[i]=dp[i]=b[i]+max_dp[q[tail]]; // no merge
        else
            max_dp[i]=dp[i]=max(b[i]+max_dp[q[tail]], dp[q[tail]]);
        //debug(dp[i]);
        q[++tail]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}
// davidlee1999WTK 2021/
// srO myk Orz
//ios::sync_with_stdio(false);