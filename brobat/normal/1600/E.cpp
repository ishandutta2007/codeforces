#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> a, b;

bool win(int i, int j, int val) {
    if(i == a.size() && j == b.size()) {
        return false;
    }
    if(i == a.size()) {
        if(val >= b[j]) return false;
        return (b.size() - j) % 2;
    }
    if(j == b.size()) {
        if(val >= a[i]) return false;
        return (a.size() - i) % 2;
    }
    if(val < a[i]) {
        if(val >= b[j]) {
            if(!win(i + 1, b.size(), a[i])) return true;
        }
        if(!win(i + 1, j, a[i])) return true;
    }
    if(val < b[j]) {
        if(val >= a[i]) {
            if(!win(a.size(), j + 1, b[j])) return true;
        }
        if(!win(i, j + 1, b[j])) return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    if(n == 1) {
        cout << "Alice";
        return;
    }
    a.push_back(v[0]);
    b.push_back(v[n - 1]);
    forn(i, 1, n) {
        if(v[i] > v[i - 1]) a.push_back(v[i]);
        else break;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(v[i] > v[i + 1]) b.push_back(v[i]);
        else break;
    }
    if(a.size() == n || b.size() == n) {
        cout << "Alice";
        return;
    }
    cout << (win(0, 0, -1) ? "Alice" : "Bob");
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