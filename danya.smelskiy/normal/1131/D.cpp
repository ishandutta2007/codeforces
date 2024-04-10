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


int n, m;
int p[1000005];
string ss[1005], s;
vector<int> v[1000005];
int x, y;
vector<int> q;
int used[1000005];
int num[1000005];
int dp[1000005];

void no() {
    cout << "No\n";
    exit(0);
}

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

void dfs(int x) {
    used[x] = 1;
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int to = v[x][i];
        if (used[to] == 2) continue;
        if (used[to] == 1) no();
        dfs(to);
    }
    used[x] = 2;
    q.push_back(x);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n + m; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        ss[i] = s;
        for (int j = 0; j < m; ++j) {
            x = get(i);
            y = get(n + j + 1);
            if (s[j] == '=') {
                if (x != y) p[y] = x;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        s = ss[i];
        for (int j = 0; j < m; ++j) {
            x = get(i);
            y = get(n + j + 1);
            if (s[j] == '=') continue;
            if (s[j] == '<') {
//                cout << x << " " << y << '\n';
                if (x == y) no();
                v[y].push_back(x);
            } else {
  //              cout << y << " " << x << '\n';
                if (x == y) no();
                v[x].push_back(y);
            }
        }
    }
    for (int i = 1; i <= n + m; ++i) {
        if (!used[i]) dfs(i);
    }
//    reverse(q.begin(), q.end());
//    for (int i = 0; i < (int)q.size(); ++i)
  //      cout << q[i] << " ";
    //cout << '\n';
    cout << "Yes\n";
    for (int i = 0; i < (int)q.size(); ++i) {
        int x = q[i];
        for (int j = 0; j < (int)v[x].size(); ++j) {
            int to = v[x][j];
            dp[x] = max(dp[x], dp[to]);
        }
        ++dp[x];
        num[x] = dp[x];
    }
    for (int i = 1; i <= n + m; ++i) {
        cout << num[get(i)] << " ";
        if (i == n || i == n + m) cout << '\n';
    }
    return 0;
}