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

int n, mnx, mny, mxx, mxy;
int x, y;
int f[100];


void upd(int x, int y, int xx, int yy) {
    mnx = max(mnx, x);
    mxx = min(mxx, xx);
    mny = max(mny, y);
    mxy = min(mxy, yy);
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        mnx = -1e5;
        mxx = 1e5;
        mny = -1e5;
        mxy = 1e5;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            int s = 0;
            for (int j = 0; j < 4; ++j) {
                cin >> f[j];
                s += f[j];
            }
            if (s == 4) continue;
            int xx1 = -1e5;
            int yy1 = -1e5;
            int xx2 = 1e5;
            int yy2 = 1e5;
            if (f[0] == 0) xx1 = x;
            if (f[1] == 0) yy2 = y;
            if (f[2] == 0) xx2 = x;
            if (f[3] == 0) yy1 = y;
            upd(xx1, yy1, xx2, yy2);
        }
        if (mnx <= mxx && mny <= mxy) cout << "1 " << mnx << " " << mny << '\n';
        else cout << "0\n";
    }
    return 0;
}