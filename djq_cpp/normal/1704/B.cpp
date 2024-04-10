#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, x, a[1000005];
void solve()
{
    cin >> n >> x;
    rep(i, n) cin >> a[i];
    int mx = -INF, mn = INF, ret = 0;
    rep(i, n) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if(mx - mn > 2 * x) {
            mx = mn = a[i]; ret ++;
        }
    }
    printf("%d\n", ret);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}