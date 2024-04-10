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

int n, l, r;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r;
    long long s = 0, s1 = 0, s2 = 0;
    for (int i = 0; i < l; ++i)
        s += (1 << i);
    n -= l;
    for (int i = 1; i <= n; ++i)
        s1 += 1;
    int last = l;
    for (int i = 1; i <= n; ++i) {
        if (last >= r) --last;
        s2 += (1 << (last));
        ++last;
    }
    cout << s1 + s << " " << s2 + s << '\n';
    return 0;
}