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
    int n, x;
    cin >> n >> x;
    int temp; 
    multiset <int> ms;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        ms.insert(temp);
    }
    int ans = 0;
    while(!ms.empty()) {
        int a = *ms.begin();
        if(ms.find(a * x) != ms.end()) {
            ms.erase(ms.find(a * x));
        } else {
            ans++;
        }
        ms.erase(ms.begin());
    }
    cout << ans << endl;
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