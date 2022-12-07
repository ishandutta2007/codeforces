#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    if(a > b) swap(a, b);
    if(n%2==0) {
        vector<int> v;
        for(int x = n/2 - a; x<=n; x += 2) {
            if(x > n/2 + a) break;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << v.size() << endl;
        for(auto j : v) cout << j << " ";
        cout << endl;
    }
    else {
        vector <int> v;
        // 1. Subtract from smaller value.
        for(int x = n/2 - a; x<=n; x+=2) {
            if(x > n/2 + a) break;
            v.push_back(x);
        }
        // 2. Add to smaller value
        for(int x = b - n/2; x<=n; x+=2) {
            if(x > n + n/2 - b + 1) break;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << v.size() << endl;
        for(auto j : v) cout << j << " ";
        cout << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}