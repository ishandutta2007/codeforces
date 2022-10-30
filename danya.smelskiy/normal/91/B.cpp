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
int a[100005];
int b[100005], ans[100005], f[100005];
map<int, int> mt;

int get(int x) {
    int res = 0;
    while (x > 0) {
        res = max(res, f[x]);
        x = (x & (x + 1)) - 1;
    }
    return res;
}

void upd(int x, int y) {
    while (x <= n) {
        f[x] = max(f[x], y);
        x = (x | (x + 1));
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int last = 0;
    for (int i = 1; i <= n; ++i)
        if (i == 1 || b[i] != b[i - 1]) {
            ++last;
            mt[b[i]] = last;
        }
    for (int i = 1; i <= n; ++i)
        a[i] = mt[a[i]];
    for (int i = n; i > 0; --i) {
        ans[i] = get(a[i] - 1);
        if (!ans[i]) ans[i] = -1;
        else ans[i] -= i + 1;
        upd(a[i], i);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    
}