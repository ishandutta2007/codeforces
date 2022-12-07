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
    int a, b, c, temp;
    cin >> a >> b >> c;
    if(a < b) swap(a, b);
    vector<vector<int>> r;
    while(b) {
        r.push_back({a % b, a, b});
        temp = a;
        a = b;
        b = temp % b;
    }
    for(auto i : r) {
        if(c >= i[0] && c <= i[1]) {
            if((c - i[0]) % i[2] == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}