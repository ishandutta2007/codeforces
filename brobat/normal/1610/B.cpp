#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool isPal(vector <int> &v, int n) {
    for(int i = 0; i < n/2; i++) {
        if(v[i] != v[n - i - 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    if(isPal(v, n)) {
        cout << "YES" << endl;
        return;
    }
    int del = -1;
    for(int i = 0; i < n/2; i++) {
        if(v[i] != v[n - i - 1]) {
            del = i;
            break;
        }
    }
    vector <int> z;
    forn(i, 0, n) {
        if(v[i] != v[del]) z.push_back(v[i]);
    }
    if(isPal(z, z.size())) {
        cout << "YES" << endl;
        return;
    }
    z.clear();
    forn(i, 0, n) {
        if(v[i] != v[n - del - 1]) z.push_back(v[i]);
    }
    if(isPal(z, z.size())) {
        cout << "YES" << endl;
        return;
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
    while(T--) solve();

    return 0;
}