#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, m, k;
vector<vector<int>> grid;
int hor[6][2] = {{0, -1}, {0, 2}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}};
int ver[6][2] = {{-1, 0}, {2, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}};

int find_hor(int a, int b) {
    vector <int> d(4, 0);
    for(int i = 0; i < 6; i++) {
        int x = a + hor[i][0];
        int y = b + hor[i][1];
        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        d[grid[x][y]]++;
    }
    for(int i = 0; i < 4; i++) {
        if(d[i] == 0) return i;
    }
    return 4;
}

int find_ver(int a, int b) {
    vector <int> d(4, 0);
    for(int i = 0; i < 6; i++) {
        int x = a + ver[i][0];
        int y = b + ver[i][1];
        if(x < 0 || y < 0 || x >= n || y >= m) continue;
        d[grid[x][y]]++;
    }
    for(int i = 0; i < 4; i++) {
        if(d[i] == 0) return i;
    }
    return 4;
}

bool check() {
    if(n % 2 == 0) {
        return (k % 2 == 0 && k <= n*(m/2));
    }
    return (k >= m/2 && (k - m/2)%2 == 0);
}

void solve() {
    cin >> n >> m >> k;
    cout << (check() ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}