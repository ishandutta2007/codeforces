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

int last[200005];
int tp, x;
int m;
int sz;
int t[1000005];

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return max(get(l, mid, ll, rr, x + x), get(mid + 1, r, ll, rr, x + x + 1));
}

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
    cin >> m;
    sz = 1;
    int y;
    while (sz < m) sz += sz;
    for (int i = 1; i <= m; ++i) {
        cin >> tp >> x;
        if (tp == 1) {
            cin >> y;
            a[x] = y;
            last[x] = i;
        } else {
            t[sz + i - 1] = x;
        }
    }
    for (int i = sz - 1; i > 0; --i)
        t[i] = max(t[i + i], t[i + i + 1]);
    for (int i = 1; i <= n; ++i) {
        cout << max(a[i], get(1, sz, last[i], m, 1)) << " ";
    }
    cout << '\n';
    return 0;
}