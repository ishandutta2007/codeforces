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




int n, m;
int a[200005], q[200005];
long long ans = 0;




int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        q[l]++;
        q[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) {
        q[i] += q[i - 1];
    }
    sort(q + 1, q + n + 1);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        ans += q[i] * 1ll * a[i];
    cout << ans << '\n';
}