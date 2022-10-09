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
#define m_tup make_tuple
#define em_bac emplace_back
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 201010

struct query {
    int type;
    int p, x;
};

int n, q;
int a[maxn];
query queries[maxn];
bool is_set[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) cin >> a[i];
    cin >> q;
    rep(i, q) {
        cin >> queries[i].type;
        if (queries[i].type == 1) cin >> queries[i].p;
        cin >> queries[i].x;
    }

    int max_payout = 0;
    for (int i = q; i--; ) {
        if (queries[i].type == 2) max_payout = max(max_payout, queries[i].x);
        else if (!is_set[queries[i].p]) {
            a[queries[i].p] = max(max_payout, queries[i].x);
            is_set[queries[i].p] = 1;
        }
    }

    rep1(i, n) {
        if (is_set[i]) continue;
        a[i] = max(a[i], max_payout);
    }

    rep1(i, n) cout << a[i] << ' ';

    return 0;
}