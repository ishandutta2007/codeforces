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


string s;
string s1, s2;
int n;
int m;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = (int)s.size();
    s = "#" + s;
    int l = 1;
    int r = n;
    while (l <= r) {
        if (l == r) {
            s1 += s[l];
            break;
        }
        if (s[l] == s[r]) {
            s1 += s[l];
            s2 += s[r];
            ++l;
            --r;
            continue;
        }
        if (r - l + 1 <= 2) {
            s1 += s[l];
            break;
        }
        if (s[l + 1] == s[r]) {
            s1 += s[l + 1];
            l += 2;
            s2 += s[r];
            --r;
            continue;
        }
        if (s[l] == s[r - 1]) {
            s1 += s[l];
            s2 += s[r - 1];
            r -= 2;
            ++l;
            continue;
        }
        ++l;
        --r;
        s1 += s[l];
        if (l != r) s2 += s[r];
        ++l;
        --r;
    }
    reverse(s2.begin(), s2.end());
    s1 += s2;
    m = (int)s1.size();
    if (m < n / 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << s1 << '\n';
    return 0;
}