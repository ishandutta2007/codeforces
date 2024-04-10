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

#define maxn 201010
int dsu[maxn];
int set_cnt;
int findp(int u) { return u == dsu[u] ? u : dsu[u] = findp(dsu[u]); }
void join(int u, int v) {
    u = findp(u);
    v = findp(v);
    if (u == v) return ;
    if (rand() & 1) swap(u, v);
    dsu[u] = v;
    --set_cnt;
}

int n, k;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep1(i, n) dsu[i] = i;
    set_cnt = n;

    rep(i, k) {
        int u, v; cin >> u >> v;
        join(u, v);
    }

    cout << max(0, k - (n - set_cnt));

    return 0;
}