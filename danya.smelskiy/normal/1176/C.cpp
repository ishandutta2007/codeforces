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



int n, x;
int cnt[100];
int ans = 0;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x == 4) x = 1;
        else if (x == 8) x = 2;
        else if (x == 15) x = 3;
        else if (x == 16) x = 4;
        else if (x == 23) x = 5;
        else x = 6;
        if (x == 1) {
            ++cnt[1];
        } else {
            if (cnt[x - 1]) {
                --cnt[x - 1];
                if (x < 6) ++cnt[x];
            } else {
                ++ans;
            }
        }
    }
    for (int i = 1; i <= 6; ++i)
        ans += cnt[i] * i;
    cout << ans << '\n';
    return 0;
}