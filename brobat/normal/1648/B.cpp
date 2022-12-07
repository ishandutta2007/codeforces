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
    int n, c;
    cin >> n >> c;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> occ(c + 1, 0);
    for(int i = 0; i < n; i++) {
        occ[v[i]] = 1;
    }
    if(occ[1] != 1) {
        cout << "No" << endl;
        return;
    }
    vector <int> nx(c + 1, 0);
    int z = -1;
    for(int i = c; i >= 0; i--) {
        if(occ[i] == 1) {
            z = i;
        }
        nx[i] = z;
    }
    for(int i = 2; i <= c; i++) {
        if(occ[i] == 0) continue;
        for(int j = i * 2; j <= c; j += i) {
            if(nx[j] == -1) continue;
            if(nx[j] < j + i) {
                if(occ[j/i] == 0) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
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