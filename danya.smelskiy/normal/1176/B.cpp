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


int cnt[1000];
int x;
int n;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            ++cnt[x % 3];
        }
        int res = cnt[0];
        int mx = 0;
        for (int i = 0; i <= cnt[1]; i += 3) {
            for (int j = 0; j <= cnt[2]; j += 3) {
                int cur = (i / 3) + (j / 3);
                cur += min(cnt[1] - i, cnt[2] - j);
                if (cur > mx) mx = cur;
            }
        }
        cout << res + mx << '\n';
    }
    return 0;
}