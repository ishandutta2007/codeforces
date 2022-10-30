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
string s;
int f[1000];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= 9; ++i) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; ++i) {
        int x = s[i] - '0';
        if (f[x] > x) {
            for (int j = i; j <= n; ++j) {
                x = s[j] - '0';
                if (f[x] >= x) {
                    s[j] = char(f[x] + '0');
                } else break;
            }
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << '\n';
}