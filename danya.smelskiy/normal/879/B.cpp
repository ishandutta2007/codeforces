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
long long m;
int a[10005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last = 0;
    for (int l = 1, r = n; ; ++l, ++r) {
        int x = a[l];
        int y = a[l + 1];
        if (x > y) {
            ++last;
            a[l + 1] = x;
            a[r + 1] = y;
        } else {
            last = 1;
            a[l + 1] = y;
            a[r + 1] = x;
        }
        if (last == m) {
            cout << max(x, y) << '\n';
            return 0;
        }
        if (l > n) {
            cout << x << '\n';
            return 0;
        }
    }
}