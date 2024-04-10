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
char s[N], t[N];
int x[N], y[N];
int nxt[N][27], last[27];
LL dp[N];
int n;
int sum[N];
int Sum(int x)
{
    int ans = 0;
    for(;x; x -= (x & -x))
    {
        ans += sum[x];
    }
    return ans;
}

void upd(int x)
{
    for(; x <= n; x += (x & (-x)))
    {
        sum[x] += 1;
    }
}
int main()
{
    int T, i;
    cin >> T;
    while(T--)
    {
        int j;
        LL ans = LL(INF) * INF;
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%s", t);
        memset(last, 0, sizeof(last));
        for(i=1;i<=n+1;i++)
        {
            for(j=0;j<=26;j++)
                nxt[i][j] = 0;
        }
        for(i=1;i<=n;i++)
        {
            sum[i] = 0;
            x[i] = s[i-1] - 'a';
            y[i] = t[i-1] - 'a';
            for(j=i;j> last[x[i]];j--)
                nxt[j][x[i]] = i;
            last[x[i]] = i;
        }
        for(i=1;i<=n;i++)
        {
            int min_l = INF;
            for(j = y[i] - 1; j >=0; j--)
            {
                if(nxt[1][j] != 0)
                    min_l = min(min_l, nxt[1][j]);
            }
            //debug(min_l);
            if(min_l != INF)
            {
                ans = min(ans, dp[i-1] + (min_l - 1 - Sum(min_l)));
            }
            int k = nxt[1][y[i]];
            //debug(k);
            if(k == 0 || k > min_l)
                break;
            dp[i] = dp[i-1] + (k - 1 - Sum(k));
            //debug(dp[i]);
            upd(k);
            nxt[1][y[i]] = nxt[k+1][y[i]];
        }
        //printf("%")
        if(ans == LL(INF) * INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
// davidlee1999WTK 2022/
// srO myk Orz
//ios::sync_with_stdio(false);
/*

6

1
a
a

3
rll
rrr

3
caa
aca

5
ababa
aabba

6
ccbbaa
aabbcd

6
ccbbaa
aabccd

*/