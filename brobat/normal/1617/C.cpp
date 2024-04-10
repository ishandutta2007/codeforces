#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n;
    cin >> n;
    vector <int> ans(n + 1, 0);
    vector <int> v;
    int temp;
    forn(i, 0, n) {
        cin >> temp;
        if(temp > n || ans[temp]) v.push_back(temp);
        else ans[temp] = 1;
    }
    bool pos = true;
    sort(v.begin(), v.end(), greater<int>());
    int x = v.size();
    int i = 0, j = n;
    // for(auto i : ans) cout << i << " ";
    // cout << endl;
    // for(auto i : v) cout << i << " ";
    // cout << endl;
    while(i < x && j > 0) {
        // i ---> Going through larger values and placing them in lower values.
        // j ---> In vector : ans, storing which values are CORRECT.
        if(ans[j] == 1) {
            j--;
            continue;
        }
        if(v[i] <= 2*j) {
            pos = false;
            break;
        }
        i++; j--;
    }
    if(!pos) cout << -1 << endl;
    else cout << x << endl;
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