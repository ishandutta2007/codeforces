#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> convert(int n) {
    vector <int> v;
    while(n) {
        v.push_back(n % 2);
        n /= 2;
    }
    reverse(v.begin(), v.end());
    return v;
}

bool possible(vector <int> &a, vector <int> &b) {
    // return true if b is of the form (111..11)(a)(1111..1111)
    int m = a.size();
    int n = b.size();
    forn(i, 0, n) {
        // Assume that a starts at index i.
        if(i + m - 1 >= n) continue;
        bool pos = true;
        forn(j, 0, i) if(b[j] == 0) pos = false;
        forn(j, 0, m) if(a[j] != b[i + j]) pos = false;
        forn(j, i + m, n) if(b[j] == 0) pos = false;
        if(pos) return true;
    }
    return false;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if(x == y) {
        cout << "YES";
        return;
    }
    vector <int> X = convert(x);
    vector <int> Y = convert(y);
    vector <int> X_trunc = X;
    while(X_trunc[X_trunc.size() - 1] == 0) X_trunc.pop_back();
    vector <int> X_add = X;
    if(X_add[X_add.size() - 1] == 0) X_add.push_back(1);
    if(possible(X_trunc, Y) || possible(X_add, Y)) {
        cout << "YES";
        return;
    }
    reverse(X_trunc.begin(), X_trunc.end());
    reverse(X_add.begin(), X_add.end());
    if(possible(X_trunc, Y) || possible(X_add, Y)) {
        cout << "YES";
        return;
    }
    cout << "NO";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}