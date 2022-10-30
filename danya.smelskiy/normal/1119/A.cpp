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

int n, ans;
int c2, pos2;
int a[300005];




int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int c1 = a[1], pos1 = 1;
    for (int i = 2; i <= n; ++i) if (a[i] != a[i - 1]) {
        c2 = a[i];
        pos2 = i;
        break;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != c1) ans = max(ans, abs(i - pos1));
        if (a[i] != c2) ans = max(ans, abs(i - pos2));
    }
    c1 = a[n];
    pos1 = n;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] != a[i + 1]) {
            c2 = a[i];
            pos2 = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != c1) ans = max(ans, abs(i - pos1));
        if (a[i] != c2) ans = max(ans, abs(i - pos2));
    }
    cout << ans << '\n';
}