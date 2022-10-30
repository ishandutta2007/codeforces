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
int a[10005], b[10005];
long long ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x = a[i - 1], y = b[i - 1];
        cin >> a[i] >> b[i];
        int xx = a[i], yy = b[i];
        if (x >= y) {
            swap(x, y);
            swap(xx, yy);
        }
        if (x < y && xx >= y) ++ans;
        if (xx <= y) {
            continue;
        }
        ans += min(xx, yy) - max(x, y);
    }
    cout << ans + 1<< '\n';
}