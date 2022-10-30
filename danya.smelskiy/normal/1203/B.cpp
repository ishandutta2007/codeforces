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
int cnt[10005];
int sz;
int q[10005];

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
        for (int i = 1; i <= 10000; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n + n + n + n; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        bool t = false;
        sz = 0;
        for (int i = 1; i <= 10000; ++i) {
            if (cnt[i] % 2) {
                t = true;
                break;
            }
            cnt[i] /= 2;
            while (cnt[i]--) {
                q[++sz] = i;
            }
        }
        int l = 1;
        int r = sz;
        int s = q[1] * q[sz];
        while (l < r) {
            if (q[l] * q[r] != s) {
                t = true;
                break;
            }
            ++l;
            --r;
        }
        cout << (t ? "NO" : "YES") << '\n';
    }
    return 0;
}