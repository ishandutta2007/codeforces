#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n, m;
    cin >> n >> m;
    bool swapped = false;
    if(n > m) {
        swap(n, m);
        swapped = true;
    }
    if(n == 1 && m == 1) {
        cout << 1 << endl;
        return;
    }
    if(n == 1 && (m == 2 || m == 3)) {
        cout << -1 << endl;
        return;
    }
    if(n == 2 && m == 2) {
        cout << -1 << endl;
        return;
    }
    vector <vector<int>> v(n, vector<int>(m));
    if(n == 2 && m == 3) {
        v = {{3, 6, 2}, {5, 1, 4}};
    }
    else if(n == 3 && m == 3) {
        v = {{8, 1, 7}, {4, 9, 2}, {6, 3, 5}};
    }
    else {
        for(int i = 0; i < n; i++) {
            // Populate v[i] with values from m*i + 1 to m*i + m.
            int x = m * i;
            int cnt = 1;
            for(int j = 1; j < m; j += 2) v[i][j] = x + (cnt++);
            for(int j = 0; j < m; j += 2) v[i][j] = x + (cnt++); 
        }
    }
    if(swapped) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << v[j][i] << " ";
            }
            cout << endl;
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}