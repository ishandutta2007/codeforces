# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;
int get_link(int x);
int gogo(int x, int y);


int link[105];
int go[105][30], nxt[105][30];
int all;
int pc[105];
int pred[105];
int n, m;
string a, b, s;
int dp[105][105][105];

int get_link(int x) {
    if (x == 0 || pred[x] == 0) return link[x] = 0;
    if (link[x] != -1) return link[x];
    return link[x] = gogo(get_link(pred[x]), pc[x]);
}

int gogo(int x, int y) {
    if (nxt[x][y] != -1) return go[x][y] = nxt[x][y];
    if (go[x][y] != -1) return go[x][y];
    if (x == 0) return go[x][y] = 0;
    return go[x][y] = gogo(get_link(x), y);
}


void init(string s) {
    for (int i = 0; i < 26; ++i)
        nxt[0][i] = go[0][i] = -1;
    for (int i = 0; i < (int)s.size(); ++i) {
        int x = s[i] - 'A';
        nxt[all][x] = all + 1;
        ++all;
        pred[all] = all - 1;
        pc[all] = x;
        link[all] = -1;
        for (int j = 0; j < 26; ++j)
            nxt[all][j] = go[all][j] = -1;
    }
    for (int i = 0; i <= all; ++i) {
        get_link(i);
    }
}

pair<pair<int, int>, int> predp[105][105][105];

void upd(int x, int y, int z, int d, int xx, int yy, int zz) {
    if (dp[x][y][z] < d) {
        dp[x][y][z] = d;
        predp[x][y][z] = make_pair(make_pair(xx, yy), zz);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> s;
    init(s);
    n = (int)a.size();
    m = (int)b.size();
    int l = (int)s.size();
    int z;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < l; ++k) {
                upd(i + 1, j, k, dp[i][j][k], i, j, k);
                upd(i, j + 1, k, dp[i][j][k], i, j, k);
                if (i < n && j < m && a[i] == b[j]) {
                    z = gogo(k, a[i] - 'A');
                    upd(i + 1, j + 1, z, dp[i][j][k] + 1, i, j, k);
                }
            }
        }
    }
    int x = n, y = m;
    z = 0;
    int res = 0;
    for (int i = 0; i < l; ++i)
        if (dp[x][y][i] > res) {
            res = dp[x][y][i];
            z = i;
        }
    if (res == 0) {
        cout << "0\n";
        return 0;
    }
    string ans = "";
    while (x && y) {
        int xx = predp[x][y][z].first.first;
        int yy = predp[x][y][z].first.second;
        int zz = predp[x][y][z].second;
        if (dp[xx][yy][zz] + 1 == dp[x][y][z]) {
            ans += a[x - 1];
        }
        x = xx, y = yy, z = zz;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}