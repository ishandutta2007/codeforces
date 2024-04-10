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
int a[300005];
vector<pair<int, int> > ans;
int pos[300005];

void swp(int x, int y) {
    ans.push_back({x, y});
    swap(a[x], a[y]);
    swap(pos[a[x]], pos[a[y]]);
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
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        if (x == i) continue;
        int y = pos[i];
        if ((y - i) * 2 >= n) {
            swp(i, y);
            continue;
        }
        if (i > n / 2) {
            swp(1, y);
            swp(1, i);
            swp(1, y);
            continue;
        }
        if (y <= n / 2) {
            swp(y, n);
            swp(i, n);
            continue;
        }
        swp(1, y);
        swp(1, n);
        swp(i, n);
        swp(1, y);
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}