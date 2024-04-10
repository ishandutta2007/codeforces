#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    map<int, int> pw;
    int o = 0, e = 0;
    forn(i, 0, n) {
        cin >> v[i];
        if(v[i] % 2) o++;
        else {
            e++;
            int temp = v[i];
            int cnt = 0;
            while(temp % 2 == 0) {
                cnt++;
                temp /= 2;
            }
            pw[cnt] += 1;
        }
    }
    int cnt = 0;
    for(auto i : pw) cnt += i.second;
    int ans = 0;
    for(auto i : pw) {
        cnt -= i.second;
        ans = (ans + binpow(2, i.second - 1) * binpow(2, cnt)) % MOD;
    }
    cout << (binpow(2, n) - ans - 1 + MOD + MOD) % MOD << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}