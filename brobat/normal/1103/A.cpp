#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

string s;
int grid[4][4];

void clear(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(grid[x][i] == 1) cnt++; 
    }
    if(cnt == 4) {
        for(int i = 0; i < 4; i++) {
            grid[x][i] = 0;
        }
    }
    cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(grid[i][y] == 1) cnt++;
    }
    if(cnt == 4) {
        for(int i = 0; i < 4; i++) {
            grid[i][y] = 0;
        }
    }
}

void hor(int x, int y) {
    for(int i = 3; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {
            if(grid[i][j] == 0 && grid[i][j + 1] == 0) {
                grid[i][j] = 1;
                grid[i][j + 1] = 1;
                cout << i + 1 << " " << j + 1 << endl;
                clear(i, j);
                clear(i, j + 1);
                return;
            }
        }
    }
}

void ver(int x, int y) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            if(grid[i][j] == 0 && grid[i+1][j] == 0) {
                grid[i][j] = 1;
                grid[i+1][j] = 1;
                cout << i + 1 << " " << j + 1 << endl;
                clear(i, j);
                clear(i+1, j);
                return;
            }
        }
    }
}

void solve() {
    cin >> s;
    memset(grid, 0, sizeof(grid));
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == '0') ver(0, 0);
        else hor(0, 0);
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