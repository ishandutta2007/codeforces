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
int a[200005];
string ans;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1;
    int r = n;
    int last = -1;
    while (l <= r) {
        if (a[l] > last && a[r] > last) {
            if (a[l] <= a[r]) {
                ans += "L";
                last = a[l];
                ++l;
            } else {
                last = a[r];
                --r;
                ans += "R";
            }
        } else if (a[l] > last) {
            last = a[l];
            ++l;
            ans += "L";
        } else if (a[r] > last) {
            last = a[r];
            --r;
            ans += "R";
        } else break;
    }
    cout << (int)ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}