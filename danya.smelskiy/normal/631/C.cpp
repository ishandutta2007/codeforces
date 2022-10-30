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

int n, m, x, y, z;
int a[200005];
set<pair<int, int> >  s;
pair<int, int> b[200005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert({a[i], i});
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].second >> b[i].first;
    }
    for (int i = m - 1; i > 0; --i)
        b[i].first = max(b[i].first, b[i + 1].first);
    for (int i = 1; i <= m; ++i)
        if (b[i].first > b[i + 1].first) {
            int x = b[i].first;
            int y = b[i + 1].first;
            while (s.size() > x) {
                int z = a[(int)s.size()];
                s.erase(make_pair(z, (int)s.size()));
            }
            while (x > y) {
                pair<int, int> xx = make_pair(a[x], x);
                pair<int, int> yy;
                if (b[i].second == 1) yy = *s.rbegin();
                else yy = *s.begin();
                if (xx == yy) {
                    s.erase(xx);
                    --x;
                    continue;
                }
                swap(a[xx.second], a[yy.second]);
                s.erase(xx);
                s.erase(yy);
                xx.second = yy.second;
                s.insert(xx);
                --x;
            }
        }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << '\n';
}