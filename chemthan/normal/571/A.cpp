#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int a, b, c, l;

void solve() {
    scanf("%d%d%d%d", &a, &b, &c, &l);
    int A = b + c - a;
    int B = c + a - b;
    int C = a + b - c;
    ll ans = 0;
    for (int d = 0; 2 * d <= l - A; d++) {
        int tmp = max(0, d + A);
        if (l - d - tmp >= 0)
        ans += 1LL * (d + 1) * (l - d - tmp + 1);
    }
    for (int d = 0; 2 * d <= l - B; d++) {
        int tmp = max(0, d + B);
        if (l - d - tmp >= 0)
        ans += 1LL * (d + 1) * (l - d - tmp + 1);
    }
    for (int d = 0; 2 * d <= l - C; d++) {
        int tmp = max(0, d + C);
        if (l - d - tmp >= 0)
        ans += 1LL * (d + 1) * (l - d - tmp + 1);
    }
    ans = 1LL * (l + 3) * (l + 2) * (l + 1) / 6 - ans;
    ans = max(ans, 0LL);
    printf("%I64d", ans);
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}