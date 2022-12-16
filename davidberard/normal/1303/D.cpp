#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

unordered_map<int, int> mp;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll have[64];
    memset(have, 0, sizeof have);
    for (int j=0; j<m; ++j) {
        int x;
        cin >> x;
        assert(mp.count(x));
        have[mp[x]]++;
    }
    ll ans = 0;
    for (ll i=0; i<62; ++i) {
        if ((n>>i)&1) {
            if (have[i]) {
                //cerr << "TAKE " << 1 << " FROM THE " << have[i] << " AVAILALBLE " << (1<<i) << "s" << endl;
                --have[i];
            } else {
                int k = -1;
                for (int j=i+1; j<32; ++j) {
                    if (have[j]) {
                        k = j;
                        break;
                    }
                }
                if (k < 0) {
                    cout << -1 << "\n";
                    return;
                }
                for (int j=k; j>i; --j) {
                    ++ans;
                    --have[j];
                    have[j-1]+=2;
                    //cerr << " SPL " << (1<<j) << " DOWN TO " << (1<<(j-1)) << " -> " << have[j] << endl;
                }
                assert(have[i]);
                --have[i];
            }

        }
        have[i+1] += have[i]/2;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i=0, j=1; i<31; i++, j*=2) {
        mp[j] = i;
    }
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}