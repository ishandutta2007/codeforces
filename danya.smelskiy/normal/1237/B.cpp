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
int a[200005];
int b[200005];
int ans;
int pos[200005];
int mx;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        pos[a[i]] = i;
    for (int i = n; i >= 1; --i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        b[i] = pos[b[i]];
        if (mx > b[i]) ++ans;
        mx = max(mx, b[i]);
    }
    cout << ans << '\n';
    return 0;
}