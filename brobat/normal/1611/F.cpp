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
    int n, s;
    cin >> n >> s;
    int l = -1;
    pair <int, int> p;
    int add = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    vector <int> v(n), pre(n);
    forn(i, 0, n) cin >> v[i];
    pre[0] = v[0];
    forn(i, 1, n) pre[i] = pre[i - 1] + v[i];
    while(end < n) {
        // Evaluate for [start, end].
        sum = pre[end];
        // cout << start << " " << end << " " << add << " " << sum << endl;
        if(sum - add + s >= 0) {
            if(end - start + 1 > l) {
                l = end - start + 1;
                p = {start + 1, end + 1};
            }
            end += 1;
        }
        else {
            add += v[start];
            start += 1;
            if(start > end) end += 1;
        }
    }
    if((*max_element(v.begin(), v.end())) + s < 0) cout << -1 << endl;
    else cout << p.first << " " << p.second << endl;
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