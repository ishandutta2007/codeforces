#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    // a < b
    int n = 2*(b - a);
    int i = b - (2*a);
    if(i < 0) {
        cout << -1 << endl;
        return;
    }
    if(b > n || a > n || c > n) {
        cout << -1 << endl;
        return;
    }
    if(c <= n/2) {
        cout << c + (n/2) << endl;
    }
    else if(c <= n){
        cout << c - (n/2) << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
    {solve();}
    return 0;
}