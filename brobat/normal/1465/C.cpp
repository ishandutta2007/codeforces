#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, m, t1, t2;
    cin >> n >> m;
    map<int, int> row; 
    map<int, int> col;
    vector <int> v(n+1, 0);
    forn(i, 0, m) {
        cin >> t1 >> t2;
        row[t1] = t2;
        col[t2] = t1;
        if(t1==t2) continue;
        v[t1]++; v[t2]++;
    }
    set <int> one;
    set <int> two;
    forn(i, 1, n+1) {
        if(v[i]==1) one.insert(i);
        if(v[i]==2) two.insert(i);
    }
    int ans = 0;
    // for(auto i : one) cout << i << " ";
    while(!one.empty() || !two.empty()) {
        // for(auto i : one) cout << i << " ";
        // cout << endl;
        if(!one.empty()) {
            ans++;
            int i = *one.begin();
            one.erase(one.begin());
            if(row[i] == 0) {
                v[i] = -1;
                v[col[i]]--;
                row[col[i]] = 0;
                if(v[col[i]] == 1) {
                    two.erase(col[i]);
                    one.insert(col[i]);
                    // cerr << col[i] << " ";
                }
                else if(v[col[i]] == 0) {
                    one.erase(col[i]);
                    // col[i] = 0;
                    // row[i] = 0;
                }

            }
            else if(col[i]==0) {
                v[i] = -1;
                v[row[i]]--;
                col[row[i]] = 0;
                if(v[row[i]] == 1) {
                    two.erase(row[i]);
                    one.insert(row[i]);
                    // cerr << row[i] << " ";
                }
                else if(v[row[i]] == 0) {
                    one.erase(row[i]);
                    // row[i] = 0;
                    // col[i] = 0;
                }
            }
        }
        else {
            int i = *two.begin();
            two.erase(two.begin());
            ans++;
            v[col[i]]--;
            row[col[i]] = 0;
            two.erase(col[i]);
            one.insert(col[i]);
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