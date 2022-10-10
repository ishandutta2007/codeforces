#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

#define NN ((int) 1e6 + 10)
long a, b, k;
vi cnt(NN);

bitset<NN> bs;
void sieveprime() {
    bs[0] = bs[1] = 1;
    cnt[0] = cnt[1] = 0;
    for (long i = 2; i < NN; ++i) {
        cnt[i] = cnt[i - 1];
        if (bs[i]) continue;
        ++cnt[i];
        for (long f = i * i; f < NN; f += i) bs[f] = 1;
    }
}

long query(long l, long r) {
    return cnt[r] - (l > 0 ? cnt[l - 1]: 0);
}

bool ok(long l) {
    for (int i = a; i <= b - l + 1; ++i) {
        if (query(i, i + l - 1) < k) return false;
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    sieveprime();
    cin >> a >> b >> k;

    if (query(a, b) < k) return cout << -1, 0;
    long ll = 1, rr = b - a + 1;
    while (ll < rr) {
        long mid = ll + (rr - ll) / 2;
        if (ok(mid)) rr = mid;
        else ll = mid + 1;
    }

    cout << ll;

    return 0;
}