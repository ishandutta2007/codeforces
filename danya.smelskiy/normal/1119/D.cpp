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


long long n, a[100005], b[100005], c[100005];



inline long long solve(long long len) {
    long long res = 0;
    int l = 1;
    int r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (b[mid] <= len) l = mid;
        else r = mid - 1;
    }
    if (b[l] <= len) {
        res += c[l];
        res += (n - 1ll - 1ll * l) * len;
    } else res += (n - 1ll) * len;
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i) {
        b[i - 1] = a[i] - a[i - 1];
    }
    sort(b + 1, b + n);
    for (int i = 1; i < n; ++i)
        c[i] = b[i] + c[i - 1];
    long long l, r;
    long long m;
    cin >> m;
    long long len;
    while (m--) {
        cin >> l >> r;
        if (n == 1) {
            cout << r - l + 1ll << " ";
            continue;
        }
        len = r - l + 1ll;
        cout << solve(len) + len << " ";
    }
    cout << '\n';
}