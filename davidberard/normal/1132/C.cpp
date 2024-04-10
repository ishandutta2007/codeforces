#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 5500;

int n, q;
int l[NMAX], r[NMAX];
int amt[NMAX];
int oc[NMAX], tc[NMAX];

/*
struct segtree {
    vector<int> t;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32-__builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, 0);
    }
    void add(int i, int v) {
        t[i+=n] +=v;
        for(i/=2, i>0; i/=2) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    int query(int l, int r) {
        int ans = 1e9;
        for(l+=n, r+=n;l<r;l/=2, r/=2) {
            if(l%2) ans = min(ans, t[l++]);
            if(r%2) ans = min(ans, t[--r]);
        }
        return ans;
    }
}; */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=q;++i) {
        cin >> l[i] >> r[i];
        amt[l[i]]++;
        amt[r[i]+1]--;
    }
    int cov = 0;
    for(int i=1;i<=n+1;++i) {
        amt[i] += amt[i-1];
        //cerr << " " << amt[i] << endl;
        if(amt[i] == 1) oc[i] = 1;
        if(amt[i] == 2) tc[i] = 1;
        if(amt[i] > 0 && i <=n) cov++;
    }
    for(int i=1;i<=n+1;++i) {
        oc[i] += oc[i-1];
        tc[i] += tc[i-1];
        //cerr << "  " << oc[i] << " " << tc[i] << endl;
    }
    ll best = 0;
    for(int i=1;i<=q;++i) {
        for(int j=i+1;j<=q;++j) {
            //cerr << "  " << l[i] << " " << r[i] << " " << l[j] << " " << r[j] << " -> ";
            int l1 = l[i];
            int l2 = l[j];
            int r1 = r[i]+1;
            int r2 = r[j]+1;
            if(l1 > l2) {
                swap(l1, l2);
                swap(r1, r2);
            }
            int m1 = 0, m2 = 0;
            if(l2 < r1) {
                if(r2 < r1) {
                    m1 = l2, m2 = r2;
                    r2 = r1;
                    r1 = m1;
                    l2 = m2;
                } else {
                    swap(r1, l2);
                    m1 = r1;
                    m2 = l2;
                }
            }
            int rem = oc[r1-1]-oc[l1-1]+oc[r2-1]-oc[l2-1]+tc[m2-1]-tc[m1-1];
            //cerr << l1 << " " << r1 << " " << m1 << " " << m2 << " " << l2 << " " << r2 << " ! " << rem << " ! " << oc[r1-1] << " " << oc[l1-1] << " " << oc[r2-1] << " " << oc[l2-1] << " " << tc[m2-1] << " " << tc[m1-1] << endl;
            best = max(best, (ll) cov-rem);
        }
    }
    cout << best << endl;
    return 0;
}