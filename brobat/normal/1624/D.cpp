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
    int n, k;
    cin >> n >> k;
    vector <int> v(26, 0);
    {
        string s;
        cin >> s;
        forn(i, 0, n) v[s[i]-'a']++;
    }
    int odd = 0;
    int sum = 0;
    forn(i, 0, 26) {
        if(v[i] % 2 == 1) {
            v[i]--;
            odd++;
        }
        sum += v[i]/2;
    }
    // cerr << sum << " " << odd << endl;
    vector <int> ans;
    int temp = k;
    forn(i, 0, k) {
        ans.push_back((sum/temp) * 2);
        sum -= (sum/temp);
        temp--;
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) ans.push_back(0);
    // for(auto i : ans) cerr << i << " "; cerr << endl;
    int z = ans.size();
    int y = min(odd, z);
    forn(i, 0, y) ans[i]++;
    int cnt = 0;
    for(int i = y; i < z; i++) {
        // ans[i] and ans[z - cnt - 1] could have a reordering of elements.
        if(z - cnt - 1 > i) {
            if(ans[z - cnt - 1] == ans[i]) continue;
            ans[z - cnt - 1]--;
            ans[i]++;
            cnt++;
        }
    }
    cout << *min_element(ans.begin(), ans.end()) << endl; 
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