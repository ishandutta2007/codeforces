#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 510;
int n, m, mod;
char s[maxn];
int col[maxn];
int cnt[2];
map<pair<pair<int, int>, int>, int> mp;

int cal(int i, int j, int k) {
    if (!k) {
        if (i == 0 && j == 0) return 1;
        return 0;
    }
    if (mp.count(make_pair(make_pair(i, j), k))) return mp[make_pair(make_pair(i, j), k)];
    ll res = 0;
    if (i > 1) res = (res + 1LL * i * (i - 1) / 2 * cal(i - 2, j + 2, k - 1)) % mod;
    if (j > 1) res = (res + 1LL * j * (j - 1) / 2 * cal(i, j - 2, k - 1)) % mod;
    if (i && j) res = (res + 1LL * i * j * cal(i - 1, j, k - 1)) % mod;
    return mp[make_pair(make_pair(i, j), k)] = res;
}

void solve() {
    ms(col, 0); ms(cnt, 0);
    scanf("%d%d%d", &n, &m, &mod);
    FOR(i, 0, m) {
        scanf("%s", s);
        FOR(j, 0, n) col[j] += s[j] - '0';
    }
    FOR(i, 0, n) {
        if (col[i] == 1) cnt[0]++;
        if (col[i] == 0) cnt[1]++;
    }
    printf("%d", cal(cnt[1], cnt[0], n - m));
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