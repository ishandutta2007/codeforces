#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 200200;
const int INF = 0x3f3f3f3f;
ll a[N];
ll p[N];
int n;

struct Bit {
    vector<ll> t;
    int n;
    Bit(int sz) {
        n = sz+1;
        t = vector<ll>(n);
    }
    void add(int x, ll va) {
        for (; x<n; x+=x&-x) {
            t[x] += va;
        }
    }
    ll query(int x) {
        ll ans = 0;
        for (; x; x-=x&-x) {
            ans += t[x];
        }
        return ans;
    }
};

struct Segtree {
    vector<ll> t, d;
    int n, h;
    Segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<ll>(n*2);
        d = vector<ll>(n*2);
    }
    void apply(int x, ll va) {
        t[x] += va;
        d[x] += va;
    }
    void push(int x) {
        if (d[x]) {
            apply(x<<1, d[x]);
            apply(x<<1|1, d[x]);
            d[x] = 0;
        }
    }
    void pull(int x) {
        t[x] = max(t[x<<1], t[x<<1|1])+d[x];
    }
    void add(int l, int r, ll val, int x, int lv, int rv) {
        if (r<=lv || rv<=l) return;
        if (l<=lv && rv<=r) {
            apply(x, val);
            return;
        }
        int mv = (lv+rv)/2;
        push(x);
        add(l, r, val, x*2, lv, mv);
        add(l, r, val, x*2+1, mv, rv);
        pull(x);
    }
    void add(int l, int r, ll val){
        add(l, r, val, 1, 0, n);
    }
    ll query(int x) {
        x+=n;
        for (int i=h; i; --i) {
            push(x>>i);
        }
        return t[x];
    }
    int queryNext(int l, int r, ll thresh, int x, int lv, int rv) {
        if (r<=lv || rv<=l) return INF;
        if (t[x] < thresh) {
            return INF;
        }
        if (x >= n) {
            ////cerr << " RET " << x << " -> " << x-n << " L R " << l << " " << r << " lv rv " << lv << " " << rv << endl;
            return x-n;
        }
        push(x);
        int mv = (lv+rv)/2;
        int ans = queryNext(l, r, thresh, x*2, lv, mv);
        if (ans < INF) return ans;
        return queryNext(l, r, thresh, x*2+1, mv, rv);
    }
    int queryNext(int l, int r, ll thresh) {
        return queryNext(l, r, thresh, 1, 0, n);
    }
};

set<int> starts;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<pii> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i].first;
    }
    for (int i=0; i<n; ++i) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    vector<pii> by_price;
    Segtree segtree(n+10);

    Bit bit(n+10);

    for (int i=0; i<n; ++i) {
        ////cerr << " :: " << v[i].first << " " << v[i].second << endl;
        a[i+1] = v[i].first;
        p[i+1] = v[i].second;
        by_price.emplace_back(v[i].second, i+1);
        segtree.add(i+1, i+2, a[i+1]-(i+1));
        bit.add(i+1, 1);
    }
    segtree.add(n+1, n+2, -1e9);
    sort(by_price.begin(), by_price.end());

    ll prv = -1e9;
    int beg = 1;
    for (int i=1; i<=n+1; ++i) {
        if (n+1 == i || segtree.query(i) >= prv) {
            starts.insert(beg);
            if (n+1 == i) break;
            prv = segtree.query(i);
            beg = i;
        }
    }

    ll ans = 0;
    starts.insert(n+1);

    for (auto& pp : by_price) {
        ll pr = pp.first;
        ll i = pp.second;
        int beg = *prev(starts.upper_bound(i));
        int nxt = *starts.upper_bound(i);
        //cerr << " :: " << a[nxt-1] << " VS " << segtree.query(nxt-1) << endl;
        //cerr << " :: " << a[beg] << " VS " << segtree.query(beg) << endl;
        ll goal = a[beg] + bit.query(nxt-1)-bit.query(beg-1)-1;
        ll jump_count = goal-a[i];
        ll contrib = jump_count*pr;
        ans += contrib;
        //cerr <<  "FOR i = " << i << " jump count " << jump_count << " price " << pr << " contrib " << contrib << " :: " << a[beg] << " bet nxt " << beg << " " << nxt << " GOAL " << goal << endl;

        segtree.add(i+1, n+2, 1);
        bit.add(i, -1);
        int lst = beg;
        while (true) {
            ll boff = segtree.query(lst);
            //cerr << " LST " << lst << " boff " << boff << endl;
            int ppos = segtree.queryNext(lst+1, n+2, boff);
            if (ppos >= nxt) break;
            lst = ppos;
            //cerr << " INSERT SEP " << lst << endl;
            starts.insert(lst);
        }
    }

    cout << ans << endl;
    
    return 0;
}