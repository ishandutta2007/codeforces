#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i];
        b[i] = a[i] + 1;
    }
    repr(i, n - 1, 0) {
        b[i] = max(b[i], b[i + 1] - 1);
    }
    rep(i, 1, n) {
        b[i] = max(b[i], b[i - 1]);
    }

    lint ans = 0;
    int c = 0;
    rep(i, 0, n) {
        if (c < b[i]) {
            c++;
            assert(c == b[i]);
        }
        ans += c - a[i] - 1;
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}