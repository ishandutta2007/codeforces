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
string ss[2];
int d[2][100005];
set<pair<int, pair<int, int> > > s;
int ans = 1e9;

void upd(int x, int y, int z) {
    if (y < 1) return;
    if (y > n) {
        ans = min(ans, z);
        return;
    }
    if (ss[x][y] == 'X') return;
    if (d[x][y] < z) return;
    s.erase({d[x][y], {x, y}});
    d[x][y] = z;
    s.insert({d[x][y], {x, y}});
    return;
}


int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> ss[0] >> ss[1];
    ss[0] = "#" + ss[0];
    ss[1] = "#" + ss[1];
    for (int i = 1; i <= n; ++i) {
        d[0][i] = d[1][i] = 1e9;
    }
    d[0][1] = 0;
    s.insert({0, {0, 1}});
    while (!s.empty()) {
        pair<int, pair<int, int> > cur = *s.begin();
        s.erase(s.begin());
        if (cur.first >= cur.second.second) continue;
        int x = cur.second.first;
        int y = cur.second.second;
        upd(x, y - 1, cur.first + 1);
        upd(x, y + 1, cur.first + 1);
        upd(1 - x, y + m, cur.first + 1);
    }
    if (ans < 1e9) cout << "YES\n";
    else cout << "NO\n";
}