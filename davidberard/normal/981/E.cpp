#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

bool isPrime(int x) {
    for(int i=2;i*i<=x;++i) {
        if(x%i == 0) return false;
    }
    return true;
}

ll mod;

void setup() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    mod = 1e9+rng()%10000000;
    while(!isPrime(mod)) ++mod;
}

const int NMAX = 10010;

ll dp[NMAX];

int n,q;

vector<int> add[NMAX];
vector<int> rem[NMAX];
int found[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    //setup();
    cin >> n >> q;
    dp[0] = 1;
    for(int i=0;i<q;++i) {
        int l, r, x;
        cin >> l >> r >> x;
        add[--l].push_back(x);
        rem[r].push_back(x);
    }
    for(int i=0;i<=n;++i) {
        for(auto& x : rem[i]) {
            for(int i=x; i<=n; ++i) {
                dp[i] = dp[i] - dp[i-x];
                //if(dp[i] < 0) dp[i] += mod;
            }
        }
        for(auto& x : add[i]) {
            for(int i=n; i>=x; --i) {
                dp[i] = dp[i] + dp[i-x];
                //if(dp[i] >= mod) dp[i] -= mod;
                if(dp[i]) found[i] = 1;
            }
        }
    }
    int k = 0;
    for(int i=1;i<=n;++i) {
        if(found[i]) ++k;
    }
    cout << k << "\n";
    for(int i=1;i<=n;++i) {
        if(found[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}