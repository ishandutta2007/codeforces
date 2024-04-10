#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 5000100;
// const int MAXN = 300;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n;
vector <int> v;
vector <int> ans;

void solve() {
    int n;
    cin >> n;
    int g = 0;
    int mx = 0;
    v.resize(MAXN, 0);
    vector <int> ini(MAXN, 0);
    ans.resize(MAXN, 0);
    forn(i, 0, n) {
        int temp;
        cin >> temp;
        g = __gcd(g, temp);
        v[temp]++;
        ini[temp]++;
        mx = max(mx, temp);
    }
    for(int i = mx; i >= 1; i--) {
        int g = (ini[i] ? i : 0);
        int cnt = ini[i];
        for(int j = i + i; j <= mx; j += i) {
            if(v[j]) {
                g = __gcd(g, j);
                cnt += ini[j];
            }
        }
        if(g == i) v[i] = cnt;
    }
    // forn(i, 0, mx + 1) cout << i << " " << v[i] << endl;
    // Now v[i] = number of values in the array that give gcd i
    for(int i = mx; i >= 1; i--) {
        ans[i] = i * v[i];
        for(int j = i + i; j <= mx; j += i) {
            ans[i] = max(ans[i], ans[j] + i * (v[i] - v[j]));
        }
    }
    cout << ans[g] << endl;
    // forn(i, 0, mx + 1) cout << i << " " << ans[i] << endl;
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