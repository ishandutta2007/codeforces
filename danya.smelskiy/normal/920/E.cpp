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
int x, y;
vector<int> v[200005];
set<int> s[200005];
set<int> ss;
int cnt;
bool used[200005];


inline bool check(int x, int y) {
    int l = 0;
    int r = (int) v[x].size() - 1;
    if (l > r) return false;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (v[x][mid] <= y) l = mid;
        else r = mid - 1;
    }
    return (v[x][l] == y);
}

set<int> :: iterator q;
void dfs(int x) {
    used[x] = true;
    ss.erase(x);
    ++cnt;
    int last = 1;
    while (last <= n) {
        q = ss.lower_bound(last);
        if (q == ss.end()) break;
        int y = *q;
        if (!check(x, y) && !used[y]) dfs(y);
        last = y + 1;
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        ss.insert(i);
        sort(v[i].begin(), v[i].end());
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) if (!used[i]) {
        cnt = 0;
        dfs(i);
        ans.push_back(cnt);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}