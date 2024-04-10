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
int a[505][505];
int res;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
        res ^= a[i][1];
    }
    if (res) {
        cout << "TAK\n";
        for (int i = 1; i <= n; ++i)
            cout << 1 << " ";
        cout << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((res ^ a[i][1] ^ a[i][j])) {
                cout << "TAK\n";
                for (int k = 1; k <= n; ++k) {
                    if (k != i) cout << "1 ";
                    else cout << j << " ";
                }
                cout << '\n';
                exit(0);
            }
        }
    }
    cout << "NIE\n";
    return 0;
}