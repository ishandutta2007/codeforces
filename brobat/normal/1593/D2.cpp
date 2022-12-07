#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

#define vector deque

bool corner(vector <int> &v, int n) {
    int mx = 0;
    int cnt = 1;
    forn(i, 1, n) {
        if(v[i] != v[i - 1]) {
            mx = max(mx, cnt);
            cnt = 0; 
        }
        cnt++;
    }
    mx = max(mx, cnt);
    return (mx * 2 >= n);
}

int max_gcd(vector <int> &v, int k) {
    // Find max value such that it is the gcd of atleast k elements in the vector.
    int g = 0;
    while(v[0] == 0) {
        g++;
        v.pop_front();
    }
    // Now we want max value such that it is the gcd of atleast (k - g) elements.
    map<int, int> m;
    for(auto i : v) {
        for(int j = 1; j <= sqrt(i); j++) {
            if(i % j == 0) {
                if(j * j == i) m[j]++;
                else {
                    m[j]++;
                    m[i/j]++;
                }
            }
        }
    }
    int mx = 0;
    for(auto i : m) {
        if(i.second >= k - g) mx = max(mx, i.first);
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    if(corner(v, n)) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for(int i = 0; i <= n/2; i++) {
        // Assume that v[i] is the least element.
        int x = v[i];
        vector <int> diff;
        for(int j = i + 1; j < n; j++) diff.push_back(v[j] - x);
        ans = max(ans, max_gcd(diff, n/2 - 1));
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}