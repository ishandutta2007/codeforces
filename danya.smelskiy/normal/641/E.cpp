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
map<int, int> mt, pos;
int all;
bool qu[100005];
vector<int> qq;
vector<pair<pair<int, int>, int> > q[100005];
int ans[100005];
int f[100005];


void update(int x, int y) {
    while (x <= 1e5) {
        f[x] += y;
        x = (x | (x + 1));
    }
    return;
}

int get(int x) {
    int res = 0;
    while (x > 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (!mt[z]) mt[z] = ++all;
        z = mt[z];
        q[z].push_back({{x, y}, i});
        if (x == 3) qu[i] = true;
        qq.push_back(y);
    }
    sort(qq.begin(), qq.end());
    int last = 0;
    for (int i = 0; i < qq.size(); ++i)
        if (!i || qq[i] != qq[i - 1]) {
            ++last;
            pos[qq[i]] = last;
        }
    for (int i = 1; i <= all; ++i) {
        for (int j = 0; j < q[i].size(); ++j) {
            q[i][j].first.second = pos[q[i][j].first.second];
            if (q[i][j].first.first == 1) update(q[i][j].first.second, 1);
            else if (q[i][j].first.first == 2) update(q[i][j].first.second, -1);
            else ans[q[i][j].second] = get(q[i][j].first.second);
        }
        for (int j = 0; j < q[i].size(); ++j) {
            if (q[i][j].first.first == 1) update(q[i][j].first.second, -1);
            else if (q[i][j].first.first == 2) update(q[i][j].first.second, 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (qu[i]) cout << ans[i] << '\n';
}