#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

#define all(x) x.begin(), x.end()
#define select find_by_order
#define rank order_of_key

using namespace std;
using namespace __gnu_pbds;

typedef int ll;
typedef vector<ll> dlist;
typedef vector<dlist> matrix;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


struct segment_tree{
    int n;
    vector<ll> st;
    segment_tree(int n) : n(n), st(4 * n) {}
    
    void update(int x, ll v) { update(1, 1, n + 1, x, v); }
    void update(int node, int a, int b, int x, ll v){
        st[node] = max(st[node], v);
        if(a + 1 == b) return;
        
        int mid = (a + b) / 2, l = node * 2, r = l + 1;
        if(x < mid) update(l, a, mid, x, v);
        else update(r, mid, b, x, v);
    }

    ll query(int x, int y) { return query(1, 1, n + 1, x, y + 1); }
    ll query(int node, int a, int b, int x, int y){
        if(x <= a && b <= y){
            return st[node];
        }
        
        int mid = (a + b) / 2, l = node * 2, r = l + 1;
        ll val;
        if(y <= mid)
            val = query(l, a, mid, x, y);
        else if(x >= mid)
            val = query(r, mid, b, x, y);
        else {
            val = query(l, a, mid, x, y);
            val = max(val, query(r, mid, b, x, y));
        }
        return val;
    }
};


void solve(int tc){
    int n;
    cin >> n;

    vector<int> data(n);
    for(auto &x: data) cin >> x;

    vector<pii> p;
    for(int i = 0; i < n; ++i){
        if(data[i] <= i + 1)
            p.push_back({data[i], i + 1 - data[i]}); // X, distance
    }
    sort(all(p));
    reverse(all(p));
    // fake element
    p.push_back(pii(-1, 2e5 + 3));

    ordered_set s;
    segment_tree st(2e5 + 10);

    // fake distance
    s.insert(2e5 + 5);

    int open = 0;
    if(!p.empty()) open = p[0].first;
    vector<pair<int, int>> foo;
    for(auto &[x, y]:p){
        if(x != open){
            open = x;
            for(auto &[z, q]:foo){
                s.insert(z);
                st.update(z + 1, q);
            }
            foo.clear();
        }
        int cur = 1;
        auto r = s.rank(y);
        auto i = *s.select(r);
        cur += st.query(i + 1, 2e5+9);
        foo.push_back(pii(y, cur));
    }
    
    cout << st.query(1, 2e5) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    for(int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}//UH top