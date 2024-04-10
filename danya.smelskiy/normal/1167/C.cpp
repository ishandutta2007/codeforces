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
int p[500005], sz[500005];

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

void mrg(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    sz[x] += sz[y];
    p[y] = x;
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        p[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        int y = 0;
        for (int j = 1; j <= x; ++j) {
            int z;
            cin >> z;
            if (j == 1) y = z;
            else mrg(y, z);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << sz[get(i)] << " ";
    cout << '\n';
    return 0;
}