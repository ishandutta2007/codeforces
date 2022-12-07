#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

vector<int> find(vector<int> &v, int x) {
    // Convert x into the mixed base v
    vector <int> ans;
    reverse(v.begin(), v.end());
    forn(i, 0, v.size()) {
        ans.push_back(x % v[i]);
        x = x / v[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    string s; cin >> s;
    vector <int> v;
    int cnt = 0;
    forn(i, 0, n) {
        if(s[i] == '*') cnt++;
        else {
            if(cnt > 0) v.push_back(k*cnt + 1);
            cnt = 0;
        }
    }
    if(cnt > 0) v.push_back(k*cnt + 1);
    // for(auto i : v) cout << i << " ";
    vector<int> a = find(v, x - 1);
    // for(auto i : a) cout << i << " ";
    int j = 0;
    if(s[0] == 'a') cout << 'a';
    forn(i, 1, n) {
        if(s[i] == 'a') {
            if(s[i - 1] == '*') {
                forn(t, 0, a[j]) cout << 'b';
                j++;
            }
            cout << 'a';
        }
    }
    if(s[n-1] == '*') forn(t, 0, a[a.size() - 1]) cout << 'b';
    cout << endl;
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