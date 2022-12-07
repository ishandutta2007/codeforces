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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> left(n, vector<int>(m, 1));
    vector<vector<int>> up(n, vector<int>(m, 1));
    left[0][0] = 1; up[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0) up[i][j] += left[i-1][j];
            if(j > 0) left[i][j] += up[i][j-1];
        }
    }
    int sum = 0;
    int free = n * m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += left[i][j];
            sum += up[i][j];
        }
    }
    for(int k = 0; k < q; k++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(left[a][b] == 0) {
            free++;
            left[a][b] = 1;
            up[a][b] = 1;
            sum += 2;
            bool c; int i, j;
            c = false;
            i = a;
            j = b;
            while(i < n && j < m) {
                if(c) {
                    if(left[i][j] == 0) break;
                    sum -= left[i][j];
                    left[i][j] = 1 + (j > 0 ? up[i][j-1] : 0);
                    sum += left[i][j];
                    c = !c;
                    i++;
                }
                else {
                    if(up[i][j] == 0) break;
                    sum -= up[i][j];
                    up[i][j] = 1 + (i > 0 ? left[i-1][j] : 0);
                    sum += up[i][j];
                    c = !c;
                    j++;
                }
            }
            i = a;
            j = b;
            c = true;
            while(i < n && j < m) {
                if(c) {
                    if(left[i][j] == 0) break;
                    sum -= left[i][j];
                    left[i][j] = 1 + (j > 0 ? up[i][j-1] : 0);
                    sum += left[i][j];
                    c = !c;
                    i++;
                }
                else {
                    if(up[i][j] == 0) break;
                    sum -= up[i][j];
                    up[i][j] = 1 + (i > 0 ? left[i-1][j] : 0);
                    sum += up[i][j];
                    c = !c;
                    j++;
                }
            }
        }
        else {
            free--;
            bool c; // if(c) go DOWN else go RIGHT
            int i, j;
            sum -= left[a][b];
            left[a][b] = 0;
            sum -= up[a][b];
            up[a][b] = 0;
            i = a + 1; 
            j = b;
            c = false;
            while(i < n && j < m) {
                if(c) {
                    if(left[i][j] == 0) break;
                    sum -= left[i][j];
                    left[i][j] = 1 + up[i][j - 1];
                    sum += left[i][j];
                    c = !c;
                    i++;
                }
                else {
                    if(up[i][j] == 0) break;
                    sum -= up[i][j];
                    up[i][j] = 1 + left[i - 1][j];
                    sum += up[i][j];
                    c = !c;
                    j++;
                }
            }
            i = a;
            j = b + 1;
            c = true;
            while(i < n && j < m) {
                if(c) {
                    if(left[i][j] == 0) break;
                    sum -= left[i][j];
                    left[i][j] = 1 + up[i][j-1];
                    sum += left[i][j];
                    c = !c;
                    i++;
                }
                else {
                    if(up[i][j] == 0) break;
                    sum -= up[i][j];
                    up[i][j] = 1 + left[i - 1][j];
                    sum += up[i][j];
                    c = !c;
                    j++;
                }
            }
        }
        cout << sum - free << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}