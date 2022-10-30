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


int n;
int pred[100005];
vector<int> v[100005];
int pred2[100005];
int sz[100005];
int all;
int res[2000005];
vector<int> q;

void dfs(int x) {
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to);
        sz[x] = max(sz[x], sz[to]);
    }
    ++sz[x];
    return;
}

void solve(int x) {
    sort(v[x].begin(), v[x].end(), [](int x, int y) {
        return sz[x] < sz[y];
    });
    q.push_back(x);
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        solve(to);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        pred[i] = x;
        v[x].push_back(i);
    }
    dfs(0);
    solve(0);
    for (int i = 0; i < q.size(); ++i) {
        if (i) cout << " ";
        cout << q[i];
    }
    cout << '\n';
    for (int i = 1; i < q.size(); ++i) {
        pred2[q[i]] = q[i - 1];
    }
    for (int i = 1; i < q.size(); ++i) {
        int x = q[i];
        while (pred[x] != pred2[x]) {
            res[++all] = x;
            pred2[x] = pred2[pred2[x]];
        }
        if (all > 1e6) {
            assert(false);
        }
    }
    cout << all << '\n';
    for (int i = 1; i <= all; ++i) {
        if (i > 1) cout << " ";
        cout << res[i];
    }
    cout << '\n';
    return 0;
}