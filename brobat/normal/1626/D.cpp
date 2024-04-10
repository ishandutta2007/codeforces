#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> pw;

void pre() {
    pw.push_back(1);
    for(int i = 1; i <= 18; i++) {
        pw.push_back(pw[i - 1] * 2);
    }
}

int lb(int a) {
    return *lower_bound(pw.begin(), pw.end(), a) - a;
}

void solve() {
    vector <int> v;
    int sum;
    {
        int n;
        cin >> n;
        sum = n;
        map<int, int> m;
        int temp;
        forn(i, 0, n) {
            cin >> temp;
            m[temp]++;
        }
        for(auto i : m) v.push_back(i.second);
    }
    int n = v.size();
    int ans = 1E9;
    for(auto x : pw) {
        for(auto y : pw) {
            int cnt_x = 0;
            int cnt_y = 0;
            forn(i, 0, n) {
                if(v[i] + cnt_x > x) break;
                cnt_x += v[i];
            }
            for(int i = n - 1; i >= 0; i--) {
                if(v[i] + cnt_y > y) break;
                cnt_y += v[i];
            }
            ans = min(ans, lb(cnt_x) + lb(cnt_y) + lb(sum - cnt_x - cnt_y));
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
    pre();
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}