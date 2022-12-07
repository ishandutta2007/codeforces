#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int p[65];
vector<string>ps; // String values of all powers of 2.

void pre() {
    p[0] = 1;
    forn(i, 1, 61) {
        p[i] = p[i-1]*2;
    }
    // cout << p[60];
    forn(i, 0, 61) {
        ps.push_back(to_string(p[i]));
    }
}

int func(string x, string y, int m, int n) {
    int i = 0; // varies from 0 to m-1
    int j = 0; // varies from 0 to n-1
    int r = 0; // The number of SIMILAR values in x and y.
    while(i < m && j < n) {
        if(x[i]==y[j]) {
            r += 1;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    return r;
}

void solve() {
    string x;
    cin >> x;
    int m = x.length();
    int ans = 1E9;
    for(auto y : ps) {
        int n = y.length();
        int z = func(x, y, m, n);
        // cerr << y << " " << z << endl;
        ans = min(ans, m + n - (2*z));
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    pre();
    int t; cin >> t; while(t--)
    {solve();}
    return 0;
}