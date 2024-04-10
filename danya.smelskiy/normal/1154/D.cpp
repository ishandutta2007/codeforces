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


int n, b, a, ans;
string s;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> b >> a;
    int bb = b;
    int aa = a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            if (a == 0 && b == 0) break;
            if (a == 0 || (b > 0 && a < aa)) {
                --b;
                ++a;
                a = min(a, aa);
                ++ans;
            } else {
                --a;
                ++ans;
            }
        } else {
            if (a) {
                --a;
                ++ans;
            } else if (b) {
                --b;
                ++ans;
            } else break;
        }
    }
    cout << ans << '\n';
}