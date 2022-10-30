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
long long b[500005];
long long a[500005];
long long x, y, z;

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n / 2; ++i) {
        cin >> b[i];
    }
    a[n] = b[1];
    int l = 2;
    int r = n - 1;
    while (l < r) {
        x = b[l];
        y = a[r + 1];
        z = max(a[l - 1], x - y);
        a[l] = z;
        a[r] = x - z;
        ++l;
        --r;
    }
    for (int i = 1;i <= n; ++i)
        cout << a[i] << " ";
    cout << '\n';
}