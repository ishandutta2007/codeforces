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
long long ans;
int a[10005];
bool t = false;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == 1) {
            if (a[i + 1] == 2) ans += 3;
            else ans += 4;
        } else if (a[i] == 2) {
            if (a[i + 1] == 1) ans += 3;
            else t = true;
        } else {
            if (a[i + 1] == 1) ans += 4;
            else t = true;
        }
    }
    for (int i = 1; i <= n - 2; ++i)
        if (a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) --ans;
    if (t) {
        cout << "Infinite\n";
        return 0;
    }
    cout << "Finite\n";
    cout << ans << '\n';
    return 0;
}