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
int a[200005];
long long q[200005];

void add(int l, int r, int x) {
    if (l <= r) {
        q[l] += x;
        q[r + 1] -= x;
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < m; ++i) {
        int x = a[i];
        int y = a[i + 1];
        if (x > y) swap(x, y);
        if (x == y) continue;
        add(1, x - 1, y - x);
        add(y + 1, n, y - x);
        add(x + 1, y - 1, y - x - 1);
        add(x, x, y - 1);
        add(y, y, x);
    }
    long long last = 0;
    for (int i = 1; i <= n; ++i) {
        last += q[i];
        cout << last << " ";
    }
    cout << '\n';
    return 0;
}