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
vector<pair<int, int> > v[100005];
vector<pair<int, int> > s[100005];
long long d[100005];

long long get_moment(int x, long long y) {
    if (s[x].size() == 0) return y;
    int l = 0;
    int r = (int)s[x].size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (s[x][mid].first <= y) l = mid;
        else r = mid - 1;
    }
    if (s[x][l].first <= y && y <= s[x][l].second) return s[x][l].second + 1;
    return y;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        vector<int> vv;
        while (x--) {
            int y;
            cin >> y;
            vv.push_back(y);
        }
        if (vv.size() == 0) continue;
        int last = vv[0];
        for (int j = 1; j < vv.size(); ++j) {
            if (vv[j - 1] + 1 == vv[j]) continue;
            s[i].push_back({last, vv[j - 1]});
            last = vv[j];
        }
        s[i].push_back({last, vv.back()});
    }
    for (int i = 1; i <= n; ++i)
        d[i] = 1e18;
    d[1] = 0;
    set<pair<long long, int> > ss;
    ss.insert({0, 1});
    while (!ss.empty()) {
        int x = ss.begin() -> second;
        ss.erase(ss.begin());
        long long xx = get_moment(x, d[x]);
        for (int j = 0; j < v[x].size(); ++j) {
            int to = v[x][j].first;
            long long len = xx + v[x][j].second;
            if (len < d[to]) {
                ss.erase({d[to], to});
                d[to] = len;
                ss.insert({d[to], to});
            }
        }
    }
    cout << (d[n] == 1e18 ? -1 : d[n]) << '\n';
}