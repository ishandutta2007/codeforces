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
string s;
int x, y;
int cnt[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> y >> x;
        int last = s[i - 1] - '0';
        for (int j = 0; j <= 1e5; ++j) {
            if (j == x || (j >= x && (j - x) % y == 0)) last = 1 - last;
            cnt[j] += last;
        }
    }
    int res = 0;
    for (int i = 0; i <= 1e5; ++i)
        res = max(res, cnt[i]);
    cout << res << '\n';
    return 0;
}