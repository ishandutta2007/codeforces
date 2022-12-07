#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int l, r;
    cin >> l >> r;
    vector <int> v(r - l + 1);
    int x = 0, y = 0;
    for(int i = l; i <= r; i++) {
        cin >> v[i - l];
        x ^= i;
        y ^= v[i - l];
    }
    if((r - l + 1) % 2 == 1) {
        cout << (x^y) << endl;
        return;
    }
    vector <int> which(17, 0);
    for(int i = l; i <= r; i++) {
        int temp = i;
        for(int j = 0; j < 17; j++) {
            if(temp % 2) {
                which[j]++;
            }
            temp /= 2;
        }
    }
    vector <int> bits(17, 0);
    int n = r - l + 1;
    for(int i = 0; i < n; i++) {
        int temp = v[i];
        for(int j = 0; j < 17; j++) {
            if(temp % 2) {
                bits[j]++;
            }
            temp /= 2;
        }
    }
    int ans = 0;
    for(int i = 0; i < 17; i++) {
        bool a = bits[i] * 2 >= n;
        bool b = which[i] * 2 >= n;
        if(a ^ b) {
            ans += (1 << i);
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}