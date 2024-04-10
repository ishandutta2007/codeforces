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
int a[2005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n + n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + n + 1);
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n + n; ++i) {
        if (i <= n) s1 += a[i];
        else s2 += a[i];
    }
    if (s1 == s2) {
        if (a[1] == a[n + n]) cout << "-1\n";
        else {
            swap(a[1], a[n + n]);
            for (int i = 1; i <= n + n; ++i)
                cout << a[i] << " ";
            cout << '\n';
        }
        return 0;
    }
    for (int i = 1; i <= n + n; ++i)
        cout << a[i] << " ";
    cout << '\n';

    return 0;
}