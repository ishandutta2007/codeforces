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


long long n, p;

long long get_cnt(long long x){
    long long res = 0;
    while (x) {
        res += x % 2ll;
        x /= 2ll;
        
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    long long x;
    for (long long i = 1; i <= 5e5; ++i) {
        x = n - p * i;
        if (x > 0) {
            if (get_cnt(x) <= i && i <= x) {
                cout << i << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}