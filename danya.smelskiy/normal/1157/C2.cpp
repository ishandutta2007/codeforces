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
int lft, rght;
int ans = -1;
int pos[200005];
int a[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last = n;
    while (last > 1 && a[last - 1] > a[last]) --last;
    for (int i = 1; i <= n; ++i) {
        pos[a[i]] = i;
    }
    if (n - last + 1 > ans) {
        ans = n - last + 1;
        lft = 0;
        rght= last;
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && a[i] <= a[i - 1]) break;
        last = max(last, pos[a[i]] + 1);
        last = max(last, i + 1);
        if (i + n - last + 1 > ans) {
            ans = i + n - last + 1;
            lft = i;
            rght= last;
        }
    }
    cout << ans << '\n';
    int i = 1;
    int j = n;
    while (i <= lft || j >= rght) {
        if (j < rght || (i <= lft && a[i] < a[j])) {
            cout << "L";
            ++i;
        } else {
            cout << "R";
            --j;
        }
    }
    cout << '\n';
    return 0;
}