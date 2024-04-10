#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;

const int M = 2*2*2*3*3*5*7;

ll f[20][1<<8][M];
int tpow[20];
ll tenpow[20];

void setup() {
    for (int i=0; i<(1<<8); ++i) {
        for (int j=0; j<M; ++j) {
            f[0][i][j] = 1;
            for (int k=0; k<8; ++k) {
                if ((i>>k)&1) {
                    f[0][i][j] &= (j%(k+2) == 0);
                }
            }
        }
    }

    tpow[0] = 1;
    tenpow[0] = 1;
    for (int i=1; i<19; ++i) {
        tpow[i] = tpow[i-1]*10%M;
        tenpow[i] = tenpow[i-1]*10;
    }

    for (int i=1; i<19; ++i) {
        for (int j=0; j<(1<<8); ++j) {
            for (int k=0; k<M; ++k) {
                int npos = k;
                for (int l=0; l<10; ++l) {
                    int nbits = j;
                    if (l >= 2) {
                        nbits |= 1<<(l-2);
                    }
                    f[i][j][k] += f[i-1][nbits][npos];
                    npos += tpow[i-1];
                    if (npos >= M) npos -= M;
                }
            }
        }
    }
}

int get_bitset(ll x) {
    int ans = 0;
    while(x) {
        if (x%10 >= 2) {
            ans |= 1<<(x%10 - 2);
        }
        x /= 10;
    }
    return ans;
}

ll get(ll x) {
    ++x;

    ll ans = 0;
    ull y=10;
    int d = 0;
    while(y <= x) {
        y*=10;
        d++;
    }
    // y stores next value
    ans = f[d][0][0];
    y/=10;
    while (d >= 0) {
        while ((ull) y+tenpow[d] <= x) {
            int pos = ((y/tenpow[d])*tenpow[d])%M;
            int bits = get_bitset(y/tenpow[d]);
            ans += f[d][bits][pos];
            y += tenpow[d];
        }

        --d;
    }
    return ans;
}

ll solve(ll l, ll r) {
    return get(r) - get(l-1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    int TT;
    cin >> TT;
    while (TT--) {
        ll l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    return 0;
}