#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n, m; cin >> n >> m;
        vector<string> a(n);
        for (auto& s: a) cin >> s;

        vector<int> cnt_row(n), cnt_col(m);
        rep(i, n) rep(f, m) {
            cnt_row[i] += a[i][f] == 'A';
            cnt_col[f] += a[i][f] == 'A';
        }
        int sum = accumulate(cnt_row.begin(), cnt_row.end(), 0);
        if (sum == n * m) {
            cout << "0\n";
            continue;
        }
        if (sum == 0) {
            cout << "MORTAL\n";
            continue;
        }
        if (cnt_row[0] == m or cnt_row.back() == m or cnt_col[0] == n or cnt_col.back() == n) {
            cout << "1\n";
            continue;
        }
        if (a[0][0] == 'A' or a[0].back() == 'A' or a.back()[0] == 'A' or a.back().back() == 'A') {
            cout << "2\n";
            continue;
        }
        bool has_full_line = false;
        rep(i, n) if (cnt_row[i] == m) {
            has_full_line = 1;
            break;
        }
        rep(i, m) if (cnt_col[i] == n) {
            has_full_line = 1;
            break;
        }
        if (has_full_line ) {
            cout << "2\n";
            continue;
        }

        if (cnt_row[0] > 0 or cnt_row.back() > 0 or cnt_col[0] > 0 or cnt_col.back() > 0) {
            cout << "3\n";
            continue;
        }
        cout << "4\n";
    }

    return 0;
}