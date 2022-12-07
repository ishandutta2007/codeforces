#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string s; cin >> s;
    int count = 0, sum = 0;
    forn(i, 0, n-1) {
        int x = s[i] - '0';
        if(x > 0) count++;
        sum += x;
    }
    sum += s[n-1] - '0';
    cout << sum + count << endl;
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