#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
const int NMAX = 1001000;

struct bit {
    vector<int> t;
    int n;
    bit() {}
    bit(int a) : n(a+1) {
        t = vector<int>(n+1, 0);
    }
    inline int lobit(const int& i) { return i&-i; }
    void assign(int i, int v) {
        ++i;
        for(;i<=n;i+=lobit(i)) {
            t[i] = max(t[i], v);
        }
    }
    int query(int i) {
        ++i;
        int ans = 0;
        for(;i;i-=lobit(i)) {
            ans = max(ans, t[i]);
        }
        return ans;
    }
};

struct seg {
    ll x, y;
    seg() {}
    seg(ll a, ll b) :x(a), y(b) {}
    bool operator< (const seg& o) const {
        return x < o.x;
    }
};

vector<seg> segs;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    segs = vector<seg>(n);
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        segs[x-1].x = i;
    }
    for(int i=0;i<n;++i) {
        int y;
        cin >> y;
        segs[y-1].y = i;
    }
    sort(segs.begin(), segs.end());
    bit b(2*n+4);
    for(int i=0;i<n;++i) {
        int v = n-segs[i].y+2;
        int best = b.query(v-1);
        b.assign(v, best+1);
    }
    cout << b.query(n+3) << endl;
    
    return 0;
}