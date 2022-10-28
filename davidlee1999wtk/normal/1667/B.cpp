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
#define N 500005
#define D 51
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;
int mv[N];
LL suf[N], a[N];
int dp[N];
int n, rk[N];
pii s[N];
void Add(int x, int val)
{
    for(;x<=n+1; x+= (x&-x))
    {
        mv[x] = max(mv[x], val);
    }
    return;
}
int Get(int x)
{
    int ans = -INF;
    for(;x; x-= (x&-x))
    {
        ans = max(mv[x], ans);
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int i, j;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d", &a[i]);
        }
        for(i=1;i<=n+1;i++)
        {
            mv[i] = -INF;
        }
        suf[n+1] = 0;
        for(i=n;i;i--)
        {
            suf[i] = suf[i+1] + a[i];
            s[i].fi = suf[i];
            s[i].se = i;
        }
        s[n+1].fi = 0;
        s[n+1].se = n+1;
        sort(s+1, s+1+n+1);
        reverse(s+1, s+1+n+1);
        dp[0] = 0;
        for(i=1;i<=n+1;i++)
        {
            rk[s[i].se] = i;
        }
        Add(rk[1], 0);
        for(i=1;i<=n;i++)
        {
            int op;
            if(a[i] > 0)
                op = 1;
            else if(a[i] == 0)
                op = 0;
            else
                op = -1;
            dp[i] = dp[i-1] + op;
            int t = Get(rk[i+1]-1) + i;
            dp[i] = max(dp[i], t);
            if(i<n)
                Add(rk[i+1], dp[i] - i);
        }
        cout<<dp[n]<<endl;
    }
    
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);