#include "bits/stdc++.h"
#include <random>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2001;
int N,
    dis[MN];
mt19937 mt(69696969);
vector<pii> edges;

void read(int r) {
    cout << ('?') << ' ' << (r) << '\n'; cout.flush();
    for (auto i = 1; i <= N; i++)
        cin >> dis[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    read(1);
    vector<int> s[2];
    for (auto i = 2; i <= N; i++)
        s[dis[i] & 1].pb(i);
    if (s[0].size() > s[1].size()) swap(s[0], s[1]);

    for (auto i = 1; i <= N; i++)
        if (dis[i] == 1)
            edges.eb(1, i);
    for (auto x : s[0]) {
        read(x);
        for (auto i = 1; i <= N; i++) {
            if (dis[i] == 1) {
                int a = x, b = i;
                if (a > b) swap(a, b);
                edges.eb(a, b);
            }
        }
    }
    UNIQUE(edges);
    shuffle(all(edges), mt);
    uniform_int_distribution<int> dis(0, 1);
    for (auto &[a, b] : edges)
        if (dis(mt))
            swap(a, b);
    cout << ('!') << '\n';
    for (auto &[a, b] : edges)
        cout << (a) << ' ' << (b) << '\n';
}