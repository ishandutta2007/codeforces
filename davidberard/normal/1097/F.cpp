#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int SZ = 7008;
const int N = 100100;

typedef bitset<SZ> mst;
//int f[N][N];
mst g[N];
mst d[SZ];
mst up[SZ];

void setup() {
    for (int i=1; i<SZ; ++i) {
        for (int j=1; j*j<=i; ++j) {
            if (i%j == 0) {
                d[i].set(j);
                d[i].set(i/j);
            }
        }
    }
    vector<vector<int>> fac(SZ);
    fac[1].push_back(1);
    for (int i=2; i<SZ; ++i) {
        if (fac[i].size() == 0) {
            for (int j=i; j<SZ; j+=i) {
                fac[j].push_back(i);
            }
        }
    }
    vector<int> nonsqr;
    nonsqr.push_back(1);
    for (int i=2; i<SZ; ++i) {
        bool good = true;
        for (auto& p : fac[i]) {
            //cerr << " " << i << " " << p << endl;
            if (i%(p*p) == 0) {
                good = false;
                break;
            }
        }
        if (good) {
            nonsqr.push_back(i);
        }
    }

    for (int i=1; i<SZ; ++i) {
        for (int j=0; j<nonsqr.size() && nonsqr[j]*i < SZ; ++j) {
            up[i].set(nonsqr[j]*i);
        }
    }
}

inline int count(const mst& x, const int& v) {
    //cerr << " ** " << up[v] << endl;
    //cerr << " ^^ " << x << endl;
    //cerr << " :: " << (x&up[v]) << endl;
    return (x&up[v]).count()%2;
}

/*
inline mst prod(const mst &x, const mst &y) {
    mst ans;
    vector<int> xv, yv;
    int xc = 0;
    while((xc = y._Find_next(xc)) != SZ) {
        xv.push_back(xc);
    }
    int yc = 0;
    while((yc = y._Find_next(yc)) != SZ) {
        yv.push_back(yc);
    }
    for (auto& xp : xv) {
        for (auto& yp : yv) {
            //cerr << " : " << xp << " " << yp << endl;
            ans.flip(__gcd(xp, yp));
        }
    }
    return ans;
} */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    int n, q;
    cin >> n >> q;
    string z;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            g[x] = d[v];
            //cerr << " g[" << x << "] " << g[x] << endl;
        } else if (t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            g[x] = g[y]^g[z];
            //cerr << " g[" << x << "] " << g[x] << endl;
        } else if (t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            g[x] = g[y]&g[z];
            //cerr << " g[" << x << "] " << g[x] << endl;
        } else if (t == 4) {
            int x, v;
            cin >> x >> v;
            z += (char) ('0' + count(g[x], v));
            //cerr << " query " << z.back() << endl;
        }

    }
    cout << z << endl;
    return 0;
}