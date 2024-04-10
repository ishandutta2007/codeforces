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

#define maxn 1010
int n, m;
int a[maxn][maxn];
vector<int> row_vals[maxn], col_vals[maxn];

void sort_unique(vector<int>& x) {
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
}

template<class T>
int bin_index_of(vector<T> const& vals, T x) {
    return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) rep(f, m) {
        cin >> a[i][f];
        row_vals[i].push_back(a[i][f]);
        col_vals[f].push_back(a[i][f]);
    }

    rep(i, n) sort_unique(row_vals[i]);
    rep(i, m) sort_unique(col_vals[i]);

    rep(i, n) {
        rep(f, m) {
            int r_id = bin_index_of(row_vals[i], a[i][f]);
            int c_id = bin_index_of(col_vals[f], a[i][f]);
            // clog << i << ' ' << f << ' ' << r_id << ' ' << c_id << endl;
            int ans = max(len(row_vals[i]) + max(0, c_id - r_id), len(col_vals[f]) + max(0, r_id - c_id));
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}