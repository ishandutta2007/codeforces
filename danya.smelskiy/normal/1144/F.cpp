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


int n, m, x, y;
vector<pair<int, pair<int, int> > > v[200005];
string s;
bool used[200005];
int clr[200005];

void dfs(int x, int y) {
    used[x] = true;
    clr[x] = y;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i].first;
        if (used[to] == false) dfs(to, 1 - y);
        else if (clr[to] != 1 - y) {
            cout << "NO\n";
            exit(0);
        }
    }
    return;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    s = "#";
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        s += "0";
        v[x].push_back({y, {i, 0}});
        v[y].push_back({x, {i, 1}});
    }
    for (int i = 1; i <= n; ++i)
        if (used[i] == false) dfs(i, 0);
    for (int i = 1; i <= n; ++i) if (clr[i]) {
        for (int j = 0; j < v[i].size(); ++j) {
            int to = v[i][j].second.first;
            s[to] = char('0' + v[i][j].second.second);
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; ++i)
        cout << s[i];
    cout << '\n';
}