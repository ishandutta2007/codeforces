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
int p[200005];
bool used[200005];
vector<int> q;
bool vis[200005];

void dfs(int x, int y) {
    if (vis[x]) return;
    vis[x] = true;
    if (!p[x]) {
        p[x] = q[y++];
        y %= q.size();
        dfs(p[x], y);
    } else dfs(p[x], y);
    return;
}

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        used[p[i]] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i]) q.push_back(i);
    if (!q.empty()) dfs(q[0], (1 % q.size()));
    for (int i = 1; i <= n; ++i)
        cout << p[i] << " ";
    cout << '\n';
    return 0;
}