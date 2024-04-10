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
int x;
int cnt[100005];
int a[100005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 1;
    set<int> s;
    int y;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (cnt[x]) {
            y = cnt[x];
            --a[y];
            if (!a[y]) s.erase(y);
        }
        ++cnt[x];
        y = cnt[x];
        ++a[y];
        s.insert(y);
        if ((int)s.size() > 2) continue;
        if ((int)s.size() == 1) {
            x = *s.begin();
            if (a[x] == 1 || x == 1) ans = i;
        } else {
            x = *s.begin();
            y = *s.rbegin();
            if (x == 1 && a[x] == 1) ans = i;
            if (y == x + 1 && a[y] == 1) ans = i;
        }
    }
    cout << ans << '\n';
}