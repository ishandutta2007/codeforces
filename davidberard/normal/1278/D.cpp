#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct obj {
    int loc, dir, ind, oth;
    obj() {}
    obj(int a, int b, int c, int d) : loc(a), dir(b), ind(c), oth(d) {}
    bool operator< (const obj& o) const {
        return loc < o.loc;
    }
};

vector<obj> v;

ll count() {
    ordered_set<pii> st;
    ll cnt = 0;
    for (auto& o : v) {
        if (o.dir == 1) {
            st.insert(pii(o.loc, o.ind));
        } else {
            st.erase(pii(o.oth, o.ind));
            cnt += st.size() - st.order_of_key(pii(o.oth, 0));
        }
    }
    return cnt;
}

const int N = 500500;
vector<int> adj[N];

void gen() {
    ordered_set<pii> st;
    for (auto& o : v) {
        if (o.dir == 1) {
            st.insert(pii(o.loc, o.ind));
        } else {
            st.erase(pii(o.oth, o.ind));
            int ord = st.order_of_key(pii(o.oth, 0));
            for (auto it = st.find_by_order(ord); it != st.end(); ++it) {
                adj[o.ind].push_back(it->second);
                adj[it->second].push_back(o.ind);
                //cerr << " : " << o.ind << " <-> " << it->second << endl;
            }
        }
    }
}

int vis[N];
int dfs(int u, int p) {
    if (vis[u]) {
        return -1;
    }
    int ans = 1;
    vis[u] = 1;
    for (auto& v : adj[u]) {
        if (p == v) continue;
        ans += dfs(v, u);
    }
    //cerr << " " << u << ":  " << ans << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, 1, i, r);
        v.emplace_back(r, -1, i, l);
    }
    sort(v.begin(), v.end());
    ll cnt = count();
    //cerr << "CNT " << cnt << endl;
    if (cnt == n-1) {
        gen();
        int amt = dfs(1, -1);
        if (amt == n) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}