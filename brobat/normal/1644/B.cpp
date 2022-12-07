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
    int n;
    cin >> n;
    int cnt = 0;
    vector <int> v(n);
    forn(i, 0, n) v[i] = i + 2;
    v[n - 1] = 1;
    do {
        bool pos = true;
        for(int i = 2; i < n; i++) {
            if(v[i-2] + v[i-1] == v[i]) {
                pos = false;
                break;
            }
        }
        if(pos) {
            cnt++;
            for(auto i : v) cout << i << " ";
            cout << endl;
            if(cnt == n) break;
        }
    } while(next_permutation(v.begin(), v.end()));
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