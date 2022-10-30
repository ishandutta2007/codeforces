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
    int x = (1 << 14) - 1;
    cout << "?";
    for (int i = 0; i < 100; ++i) {
        cout << " " << i;
    }
    cout << endl;
    int y;
    cin >> y;
    int res = 0;
    for (int i = 0; i < 7; ++i)
        if (y & (1 << i)) y ^= (1 << i);
    res = y;
    cout << "?";
    for (int i = 1; i <= 100; ++i)
        cout << " " << (i << 7);
    cout << endl;
    cin >> y;
    for (int i = 7; i <= 15; ++i)
        if (y & (1 << i)) y ^= (1 << i);
    cout << "! " << res + y << endl;
    return 0;
}