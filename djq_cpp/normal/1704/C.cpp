#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, a[1000005], b[1000005];
void solve()
{
    cin >> n >> m;
    rep(i, m) cin >> a[i];
    sort(a, a + m);
    a[m] = a[0] + n;
    rep(i, m) b[i] = a[i + 1] - a[i] - 1;
    sort(b, b + m);
    reverse(b, b + m);
    LL ans = m;
    if(b[0] == 0) ans = n;
    else rep(i, m) ans += (4 * i + 1 == b[i] ? -1 : 0) + min(4 * i + 1, b[i]);
    printf("%lld\n", ans);
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