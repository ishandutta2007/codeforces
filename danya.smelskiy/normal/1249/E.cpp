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
int c;
int all;
int p[200005][2];
int a[200005];
int b[200005];
long long d[400005];
vector<pair<int, int> > v[400005];


void add(int x, int y, int xx, int yy, int l) {
    x = p[x][y];
    xx = p[xx][yy];
    v[x].push_back({xx, l});
}

void dij() {
    for (int i = 1; i <= all; ++i)
        d[i] = 1e18;
    d[1] = 0;
    set<pair<long long, int> > s;
    s.insert({0, 1});
    while (!s.empty()) {
        int x = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i < v[x].size(); ++i) {
            int to = v[x][i].first;
            long long len = v[x][i].second + d[x];
            if (len < d[to]) {
                s.erase({d[to], to});
                d[to] = len;
                s.insert({d[to], to});
            }
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        p[i][0] = ++all;
        p[i][1] = ++all;
        add(i, 0, i, 1, c);
        add(i, 1, i, 0, 0);
    }
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        add(i, 0, i + 1, 0, a[i]);
        add(i + 1, 0, i, 0, a[i]);
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
        add(i, 1, i + 1, 1, b[i]);
        add(i + 1, 1, i, 1, b[i]);
    }
    dij();
    for (int i = 1; i <= n; ++i)
        cout << d[p[i][0]] << " ";
    cout << '\n';
    return 0;
}