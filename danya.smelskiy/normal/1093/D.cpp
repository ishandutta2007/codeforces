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
const long long md = 998244353;


int clr[300005];
bool used[300005];
vector<int> v[300005];
long long p[300005];
int n, m, c1, c2;
bool cl = false;


void cll(int n, int m) {
    for (int i = 1;i <= n; ++i) {
        used[i] = false;
        v[i].clear();
    }
}

void dfs(int x, int y = 0) {
    if (used[x]) {
        if (clr[x] != y) {
            cl = true;
        }
        return;
    }
    used[x] = true;
    clr[x] = y;
    if (y == 0) ++ c1;
    else ++c2;
    for (int i = 0;i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, 1 - y);
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    p[0] = 1;
    for (int i = 1;i <= 300001; ++i) {
        p[i] = p[i-1] + p[i-1];
        if (p[i] >= md) p[i] -= md;
    }
    int t;
    cin >> t;
    long long res, cur;
    int x, y;
    while (t--) {
        cin >> n >> m;
        cll(n, m);
        for (int i = 1;i <= m; ++i) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        res = 1;
        for (int i = 1;i <= n; ++i) if (used[i] == false) {
            c1 = 0, c2 = 0;
            cl = false;
            dfs(i);
            if (cl) {
                res = 0;
                break;
            }
            cur = p[c1] + p[c2];
            if (cur >= md) cur -= md;
            res = (res * cur) % md;
        }
        cout << res << '\n';
    }
}