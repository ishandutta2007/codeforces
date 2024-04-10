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



int n, m, k, q;
bool used[200005];
int a[200005];

bool f(int mid) {
    for (int i = 1; i <= n; ++i)
        used[i] = false;
    for (int i = 1; i <= mid; ++i)
        used[a[i]] = true;
    int last = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) last = 0;
        else ++last;
        if (last == m) {
            last = -1;
            ++res;
        }
    }
    return (res >= k);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    cin >> q;
    for (int i = 1; i <= q; ++i)
        cin >> a[i];
    int l = 1;
    int r = q + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (!f(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (l == q + 1 ? -1 : l) << '\n';
}