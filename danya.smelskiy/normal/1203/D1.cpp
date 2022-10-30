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


string a, b;
int suff[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    int r = (int)b.size() - 1;
    suff[r + 1] = (int)a.size();
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] == b[r]) {
            suff[r] = i;
            --r;
            if (r == -1) break;
        }
    }
    int ans = suff[0];
    int l = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] == b[l]) {
            ++l;
            if (suff[l] > i) ans = max(ans, suff[l] - i - 1);
            if (l == (int)b.size()) break;
        }
    }
    cout << ans << '\n';
    return 0;
}