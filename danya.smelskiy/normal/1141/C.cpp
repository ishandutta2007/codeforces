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
long long x;
long long a[200005], b[200005], c[200005];
long long mx = -1e9;
int pos;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        a[i + 1] = a[i] + x;
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] > mx) {
            mx = a[i];
            pos = i;
        }
    for (int i = 1; i <= n; ++i)
        c[i] = b[i] = a[i] - a[pos] + n;
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; ++i)
        if (c[i] != i) {
            cout << "-1\n";
            return 0;
        }
    for (int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << '\n';
}