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
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 5; i <= n; ++i)
        if (n % i == 0 && n / i >= 5) {
            int x = i;
            int y = n / i;
            string s = "aeiou";
            for (int i = 1; i <= x; ++i) {
                for (int j = 1; j <= y; ++j)
                    cout << s[(j - 1) % 5];
                string ss = "";
                for (int j = 1; j <= 4; ++j)
                    ss += s[j];
                ss += s[0];
                s = ss;
            }
            cout << '\n';
            return 0;
        }
    cout << "-1\n";
    return 0;
}