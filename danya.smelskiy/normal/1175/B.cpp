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
const long long md = (1ll << (32ll)) - 1ll;

int n;
long long num[100005];
long long ans[100005];
int sz;
string tp[100005];
int q[100005];
int x;
long long cur;

inline void no() {
    cout << "OVERFLOW!!!\n";
    exit(0);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    num[0] = 1;
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> tp[i];
        if (tp[i] == "add") {
            cur = num[q[sz]];
            ans[q[sz]] += cur;
            if (ans[q[sz]] > md) no();
        } else if (tp[i] == "for") {
            cin >> x;
            ++all;
            q[++sz] = all;
            num[all] = x;
        } else {
            cur = num[q[sz - 1]] * ans[q[sz]] + ans[q[sz - 1]];
            if (cur > md) no();
            --sz;
            ans[q[sz]] = cur;
        }
    }
    cout << ans[q[sz]] << '\n';
    return 0;
}