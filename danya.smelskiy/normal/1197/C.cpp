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
int a[300005];
vector<int> v;
int ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    --m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i > 1) {
            int w = a[i] - a[i - 1];
            v.push_back(w);
            ans += w;
        }
    }
    sort(v.begin(), v.end(), [](int x, int y) {
        return x > y;
    });
    for (int i = 0; i < m; ++i)
        ans -= v[i];
    cout << ans << '\n';
    return 0;
}