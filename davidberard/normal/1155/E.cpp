#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 50;
const int MOD = 1000003;

int x[N];
int f[N];
int a[N];
int n;

int pow(int b, int p) {
    int ans = 1;
    for (int i=0; i<22; ++i) {
        if ((p>>i)&1) {
            ans = (ll) ans*b%MOD;
        }
        b = (ll) b*b%MOD;
    }
    return ans;
}

inline int modinv(int x) {
    return pow(x, MOD-2);
}

int m[N][N];

void swap_row(int i, int j) {
    if (i==j) return;
    for (int k=0; k<12; ++k) {
        swap(m[i][k], m[j][k]);
    }
}

bool get_a(int b) {
    for (int i=0; i<11; ++i) {
        int v = 1;
        for (int j=0; j<11; ++j) {
            m[i][j] = v;
            v = (ll) v*x[i+b]%MOD;
        }
        m[i][11] = f[i+b];
    }

    int sz = 0;
    for (int i=0; i<11; ++i) {
        //cerr << "\n at " << i << endl;
        //cerr; for (int j=0; j<11; ++j) {
            //cerr; for (int k=0; k<12; ++k) {
                //cerr << " " << m[j][k];
            //cerr; } //cerr << endl;
        //cerr; }

        int rw = -1;
        for (int j=i; j<12; ++j) {
            if (m[j][i]) {
                rw = j;
                //break;
            }
        }
        if (rw == -1) break;
        swap_row(rw, i);
        int inv = modinv(m[i][i]);
        for (int j=i; j<12; ++j) {
            m[i][j] = (ll) m[i][j]*inv%MOD;
        }
        for (int j=i+1; j<11; ++j) {
            int f = m[j][i];
            for (int k=i; k<12; ++k) {
                m[j][k] = (MOD + m[j][k] - (ll) f*m[i][k]%MOD)%MOD;
            }
        }
        sz = i+1;
    }
    if (sz != 11) {
        return false;
    }

    for (int i=10; i>=0; --i) {
        for (int j=i-1; j>=0; --j) {
            int f = m[j][i];
            for (int k=i; k<12; ++k) {
                m[j][k] = (MOD + m[j][k] - (ll) f*m[i][k]%MOD)%MOD;
            }
        }
    }

    for (int i=0; i<11; ++i) {
        a[i] = m[i][11];
    }

    return true;
}

int g(int x) {
    ll ans = 0;
    ll b = 1;
    for (int i=0; i<11; ++i) {
        ans += b*a[i]%MOD;
        b = b*x%MOD;
    }
    return ans%MOD;
}

int solve() {
    for (int i=0; i<11; ++i) {
        //cerr << a[i] << " ";
    }
    //cerr << endl;
    for (int i=0; i<MOD; ++i) {
        if (g(i) == 0) {
            return i;
        }
    }
    //cerr << "!! " << g(MOD-3) << endl;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i=0; i<=40; ++i) {
        x[i] = i;
        cout << "? " << x[i] << endl;
        cin >> f[i];
    }

    for (int i=0; i<25; ++i) {
        if (get_a(i)) {
            cout << "! " << solve() << endl;
            return 0;
        }
        assert(false);
    }
    assert(false);
    return 0;
}