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

void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    map<int, vector<int>> occ;
    forn(i, 0, n) {
        cin >> v[i].second;
        v[i].first == i;
        occ[v[i].second].push_back(i);
    }
    vector <int> ans;
    int it = 0;
    while(it < n) {
        int mex = 0;
        int final_index = it;
        forn(i, 0, n + 1) {
            if(occ[i].size() == 0) {
                break;
            }
            else {
                mex++;
                final_index = max(final_index, occ[i][0]);
            }
        }
        // cout << final_index << endl;
        ans.push_back(mex);
        for(int i = it; i <= final_index; i++) {
            // v.pop_front();
            occ[v[i].second].pop_front();
            // cout << i << " popped" << " ";
        }
        // cout << endl;
        it = final_index + 1;
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;
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