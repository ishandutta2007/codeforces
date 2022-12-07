#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool compare(int a, int b, int c) {
    if(a>=c && b<=c) return true;
    if(a<=c && b>=c) return true;
    return false;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int>> v(n+1);
    forn(i, 0, n) cin >> v[i].first >> v[i].second;
    v[n].first = 1E18; v[n].second = 0;
    pair<int, int> pos = {1, -v[0].first};
    if(v[0].second < 0) {
        pos.first *= -1;
        pos.second *= -1;
    }
    int end = v[0].first + abs(v[0].second); // End time.
    forn(i, 1, n+1) {
        if(end <= v[i].first) {
            int a = pos.first*v[i-1].first + pos.second;
            int b = pos.first*end + pos.second;
            if(compare(a, b, v[i-1].second)) ans++;
            if(v[i].second >= b) {
                pos = {1, b - v[i].first};
            }
            else {
                pos = {-1, b + v[i].first};
            }
            end = v[i].first + abs(v[i].second - b);
        }
        else {
            int a = pos.first*v[i-1].first + pos.second;
            int b = pos.first*v[i].first + pos.second;
            if(compare(a, b, v[i-1].second)) ans++;
        }
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
    while(T--) solve();

    return 0;
}