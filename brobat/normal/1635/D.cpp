#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

const int MOD = 1000000000 + 7;
const int MAXN = 200100;

int dp[MAXN], s[MAXN];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, p;
    cin >> n >> p;
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= p + 4; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    s[0] = 1;
    for(int i = 1; i <= p + 4; i++) {
        s[i] = (s[i - 1] + dp[i]) % MOD;
    }
    vector <int> v(n);
    map<int, bool> f;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int x = v[i];
        bool found = false;
        while(x) {
            if(x % 2 == 1) {
                x /= 2;
            } 
            else if(x % 4 == 0) {
                x /= 4;
            }
            else {
                break;
            }
            if(f.find(x) != f.end()) {
                found = true;
                break;
            }
        }
        if(!found) {
            f[v[i]] = true;
        }
    }
    int ans = 0;
    for(auto i : f) {
        int x = i.first;
        int b = 0;
        while(x) {
            b++;
            x /= 2;
        }
        if(p - b < 0) continue;
        ans = (ans + s[p - b]) % MOD;
        // cout << p << " " << b << endl;
    }
    cout << ans;

    return 0;
}