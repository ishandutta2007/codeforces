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




int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int l, r, ll, rr;
        cin >> l >> r >> ll >> rr;
        int p1 = 0, p2 = 0;
        for (int j = l; j <= r; ++j) {
            if (ll < j) {
                p1 = j;
                p2 = ll;
                break;
            } else if (rr > j) {
                p1 = j;
                p2 = rr;
                break;
            }
        }
        cout << p1 << " " << p2 << '\n';
    }
}