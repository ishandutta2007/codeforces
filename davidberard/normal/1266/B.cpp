#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 2000;

int dp[N][10];
int opp[10];

void setup() {
    opp[1] = 6;
    opp[2] = 5;
    opp[3] = 4;
    opp[4] = 3;
    opp[5] = 2;
    opp[6] = 1;
    int sm = 1+2+3+4+5+6;
    dp[0][0] = 1;
    for (int i=0; i<500; ++i) {
        for (int j=0; j<N; ++j) {
            for (int k=0; k<=6; ++k) {
                if (dp[j][k] == 0) continue;
                for (int l=1; l<=6; ++l) {
                    if (j+sm-k-l < N) {
                        dp[j+sm-k-l][opp[l]] = 1;
                    }
                }
            }
        }
    }
}

bool solve(ll x) {
    if (x < 15) return false;
    return (x-15)%14 < 6;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    /*
    for (int i=1; i<N; ++i) {
        int dpr = 0;
        for (int j=1; j<=6; ++j) {
            dpr |= dp[i][j];
        }
        assert(dpr == solve(i));
    }
    */
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << (solve(x) ? "YES" : "NO") << "\n";
    }
    return 0;
}