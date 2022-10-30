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

long long n;
vector<long long> ans;
int cnt;

inline bool check(long long n) {
    if (n == 0) return true;
    long long x = 0;
    for (long long i = 0; i <= 50; ++i)
        if (n & (1ll << i)) x = i;
    ++x;
    x = (1ll << x) - 1ll;
    return x == n;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    while (!check(n)) {
        long long x = 0;
        for (long long i = 0; i <= 50; ++i)
            if (n & (1ll << i)) {
                x = i;
            }
        ++cnt;
        ++x;
        ans.push_back(x);
        n ^= (1ll << x) - 1ll;
        if (!check(n)) {
            ++cnt;
            ++n;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}