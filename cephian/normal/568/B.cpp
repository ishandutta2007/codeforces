#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll part[4001];

ll pow(ll a, ll b) {
    if(b==0) return 1;
    ll t = pow(a, b/2);
    t = (t*t) % MOD;
    if(b&1) t = (t*a) % MOD;
    return t;
}

ll bell[4001][4001];


int main() {
    ll n;
    cin >> n;
    bell[0][0] = 1;
    bell[1][1] = 1;
    for(int i = 2; i <= n; ++i) {
        bell[i][1] = bell[i-1][i-1];
        for(int j = 2; j <= n; ++j)
            bell[i][j] = (bell[i][j-1] + bell[i-1][j-1])%MOD;
    }
    
    
    ll ans = 0;
    
    ll ncr = 1;
    for(int r = 0; r < n; ++r) {
        if(r > 0) {
            ncr = (ncr*(n-r+1))%MOD;
            ncr = (ncr*pow(r, MOD-2))%MOD;
        }
//        cout << r << "->" << ncr << endl;
        ans = (ans+ncr*bell[r][r])%MOD;
    }
    cout << ans << endl;
    return 0;
}