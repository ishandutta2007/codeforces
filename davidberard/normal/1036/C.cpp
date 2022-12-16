#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll dp[19][5]; // how many with i+1 digits where the first digit is 1 have j zeros
ll dp2[19][5]; // how many from (0, 10^i] have j zeros

void setup() {
    ll tpow = 10;
    dp[0][1] = 1;
    dp2[0][1] = 1;
    for(int i=1;i<19;++i) {
        for(int j=0;j<i;++j) {
            for(int k=1;k<5;++k) {
                dp[i][k] += dp[j][k-1]*9;
            }
            dp[i][4] += dp[j][4]*9;
        }
        ++dp[i][1];
        for(int j=0;j<i;++j) {
            for(int k=0;k<5;++k) {
                dp2[i][k] += dp[j][k]*9;
            }
        }
        dp2[i][1]++;
        for(int k=0;k<5;++k) {
                //cerr << " dp2 " << i << " " << k << " = " << dp2[i][k] << endl;
            //cerr << " dp " << i << " " << k << " = " << dp[i][k] << endl;
        }
    }
}

ll f(ll x) {
    vector<int> digs;
    ll y = x;
    ll ans = 0;
    for(int i=0;y; y/=10, i++) {
        digs.push_back(y%10);
        //cerr << " ! " << digs.back() << endl;
    }
    int extra = 0;
    for(int i=digs.size()-1;i>=0;--i) {
        if(digs[i] != 0) {
            for(int j=max(0, 4-extra);j<5;++j) {
                ans += dp2[i][j];
                //cerr << " for 0 to 2^" << i << " we get add for j=" << j << ", " << dp2[i][j] << endl;
            }
            for(int j=max(0, 4-extra);j<5;++j) {
                ans += (digs[i]-1)*dp[i][j];
                //cerr << " for up to this value we add for i " << i << " we get add for j=" << j << ", " << (digs[i]-1)*dp[i][j] << endl;
            }
            ++extra;
        }
    }
    return x-ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    int q;
    cin >> q;
    for(int i=0;i<q;++i) {
        ll l, r;
        cin >> l >> r;
        cout << f(r)-f(l-1) << "\n";
    }
    return 0;
}