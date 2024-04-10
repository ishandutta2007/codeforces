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



inline bool check(string &s) {
    int n = (int)s.size() - 1;
    for (int i = 1; i <= n / 2; ++i)
        if (s[i] != s[n - i + 1]) return false;
    return true;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    s = "#" + s;
    for (int i = 1; i < n; ++i) {
        string ss = "#";
        for (int j = i + 1; j <= n; ++j)
            ss += s[j];
        for (int j = 1; j <= i; ++j)
            ss += s[j];
        if (ss != s && check(ss)) {
            cout << 1 << '\n';
            return 0;
        }
    }
    if (n & 1) s[(1 + n + 1) / 2] = s[1];
    for (int i = 2; i <= n; ++i)
        if (s[i] != s[i - 1]) {
            cout << 2 << '\n';
            return 0;
        }
    cout << "Impossible\n";
    return 0;
}