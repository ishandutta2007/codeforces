#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1000100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(MAXN, 0);
    forn(i, 0, n) {
        int temp;
        cin >> temp;
        v[temp] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= MAXN; i++) {
        int temp = 0;
        for(int j = i; j <= MAXN; j+=i) {
            if(v[j] == 1) {
                temp = gcd(j, temp);
            }
        }
        if(temp == i) {
            v[i] = 1;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0) - n;
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