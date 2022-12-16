#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int MSZ = (1<<18)*22;

ll val[MSZ];
int le[MSZ], ri[MSZ];

struct PersistentSegtree {
    //vector<ll> val;
    //vector<int> le, ri;
    int n, h, cur, latest;
    PersistentSegtree() {}
    PersistentSegtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        //val = vector<ll>((n+1)*(h+4), 0);
        //le = ri = vector<int>((n+1)*(h+4), 0);
        for (int i=1; i<n; ++i) {
            le[i] = i*2;
            ri[i] = i*2+1;
        }
        cur = 2*n-1;
        latest = 1;
    }
    int last() const {
        return latest;
    }
    int modify(int pos, ll amt, int root, int lv, int rv) {
        if (pos<lv || pos>=rv) return root;
        int now = ++cur;
        //////cerr << " NOW " << now << " VS ROOT " << root << " VS SIZE " << val.size() << endl;
        assert (now < MSZ);
        val[now] = val[root]+amt;
        //////cerr << " OLD " << val[root] << " (" << root << ") "<< " NEW " << val[now] << endl;
        if (rv-lv == 1) return now;

        int mv = (lv+rv)/2;
        le[now] = modify(pos, amt, le[root], lv, mv);
        ri[now] = modify(pos, amt, ri[root], mv, rv);
        return now;
    }
    int modify(int root, int pos, ll amt) {
        return latest = modify(pos, amt, root, 0, n);
    }
    ll query(int root, int l, int r, int lv, int rv) {
        if (r<=lv || rv<=l) return 0;
        if (l<=lv && rv<=r) {
            return val[root];
        }
        int mv = (lv+rv)/2;
        ll ans = 0;
        ans += query(le[root], l, r, lv, mv);
        ans += query(ri[root], l, r, mv, rv);
        return ans;
    }
    ll query(int root, int l, int r) {
        ////cerr << "QUERY ON " << root << " FROM " << l << " TO " << r << endl;
        ll res = query(root, l, r, 0, n);
        ////cerr << "  RES " << res << endl;
        return res;
    }
};

const int N = 200200;
int marker[N];
ll p[N], a[N], ord[N];
ll ans[N];
PersistentSegtree segtree;
int n;

void solve(int lo, int hi, int plo, int phi) {
    if (lo > hi) return;

    int mi = (lo+hi)/2;

    ll base = segtree.query(marker[n], 1, plo+1)-segtree.query(marker[mi], 1, plo+1)+segtree.query(marker[mi], plo+1, n+1);
    ////cerr << "   ";
    ////cerr << segtree.query(marker[n], 1, plo+1) << " - " << segtree.query(marker[mi], 1, plo+1) << " + " << segtree.query(marker[mi], plo+1, n+1) << endl;

    ////cerr << " BASE " << base << endl;

    pii best(1e18, -1);

    for (int i=plo; i<=phi; ++i) {
        best = min(best, pii(base, i));
        if (i != phi) {
            if (p[i+1] > mi) {
                base += a[i+1];
            } else {
                base -= a[i+1];
            }
        }
    }
    
    //cerr << "SOLVE " << mi << " GET " << best.first << " (at " << best.second << ")" << endl;

    ans[mi] = best.first;
    solve(lo, mi-1, plo, best.second);
    solve(mi+1, hi, best.second, phi);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> p[i];
        ord[p[i]] = i;
    }
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        ////cerr << " :: " << a[i] << endl;
    }
    segtree = PersistentSegtree(n+10);

    int latest = 1;
    for (int i=1; i<=n; ++i) {
        int j = ord[i];
        latest = marker[i] = segtree.modify(latest, j, a[j]);
        ////cerr << " MARKER " << i << " = " << marker[i] << " :: j " << j << endl;
        ////cerr << " :: " << segtree.query(marker[i], 1, 2) << endl;
        ////cerr << " :: " << segtree.query(marker[i], 2, 3) << endl;
        ////cerr << " :: " << segtree.query(marker[i], 3, 4) << endl;
        ////cerr << " :: " << segtree.query(marker[i], 1, 3) << endl;
        ////cerr << " :: " << segtree.query(marker[i], 2, 4) << endl;
        ////cerr << " :: " << segtree.query(marker[i], 1, 4) << endl;
    }

    solve(0, n, 1, n-1);
    ll overall = 1e18;
    for (int i=0; i<=n; ++i) {
        overall = min(overall, ans[i]);
    }
    cout << overall << "\n";
    return 0;
}