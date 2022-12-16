#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353LL;

ll tpow[1000010];
void setup() {
    tpow[0] = 1;
    for(int i=1;i<1000010;++i) {
        tpow[i] = (tpow[i-1]*2)%MOD;
    }
}

ll get_num(ll i) {
    if(i == 0) return 1;
    return (tpow[i-1]*(i+2))%MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    int N;
    cin >> N;
    vector<ll> a(N);
    for(auto& ii : a) cin >> ii;
    ll ans = 0;
    for(int i=0;i<N;++i) {
        //cerr << "!! " << get_num(N-i-1) << endl;
        ans = (ans + get_num(N-1-i)*a[i])%MOD;
        //cerr << " " << ans << " " << get_num(N-1-i) << endl;
    }
    cout << ans << endl;
    
    return 0;
}