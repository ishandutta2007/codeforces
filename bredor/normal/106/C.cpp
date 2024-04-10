//  228

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX5 100005
#define MAX6 1000006
#define MAX7 10000007
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sline(a) scanf("%[^\n]%*c", a);
#define pf(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define pfs(a) printf("%s\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
#define Mod 998244353
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

const int N = MAX5;

int main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
    //#endif

    FASTIO;
    int n, m, c0, d0;
    cin>>n>>m>>c0>>d0;
    int a[m+1], b[m+1], c[m+1], d[m+1];
    for(int i = 1; i <= m; i++) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int dp[n+1][m+1];
    mem(dp, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= (a[j]/b[j]); k++) {
                int lagbe = c[j] * k;
                if(i-lagbe>=0) {
                    dp[i][j] = max(dp[i][j], dp[i-lagbe][j-1] + (d[j] * k));
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int k = 0; k <= (n/c0); k++) {
            int lagbe = k * c0;
            if(i-lagbe>=0)
            dp[i][m] = max(dp[i][m], dp[i-lagbe][m] + (d0 * k));
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}