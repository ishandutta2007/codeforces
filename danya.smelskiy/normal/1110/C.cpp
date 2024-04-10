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


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int y = x;
        int cur = 0;
        while (y) {
            if (!(y & 1)) ++cur;
            y >>= 1;
        }
        if (cur) {
            int res = 0;
            int last = 0;
            while ((1 << last) <= x) {
                res |= (1 << last);
                last++;
            }
            cout << res << '\n';
            continue;
        }
        int res = 1;
        for (int i = 2; i * i <= x; ++i)
            if (x % i == 0) {
                if (x / i > res) res = x / i;
            }
        cout << res << '\n';
    }
    
}