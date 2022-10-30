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

inline long long get_number(string s) {
    long long res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res *= 3;
        res += s[i] - '0';
    }
    return res;
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
        long long x;
        cin >> x;
        string res = "";
        while (x) {
            res += char('0' + x % 3ll);
            x /= 3ll;
        }
        reverse(res.begin(), res.end());
        int pos = -1;
        for (int i = 0; i < res.size(); ++i)
            if (res[i] == '2') {
                pos = i;
                break;
            }
        if (pos == -1) {
            cout << get_number(res) << '\n';
            continue;
        }
        while (pos >= 0 && res[pos] != '0') --pos;
        if (pos == -1) {
            for (int i = 0; i < res.size(); ++i)
                res[i] = '0';
            res = "1" + res;
            cout << get_number(res) << '\n';
            continue;
        }
        res[pos] = '1';
        for (int i = pos + 1; i < res.size(); ++i)
            res[i] = '0';
        cout << get_number(res) << '\n';
    }
    return 0;
    return 0;
}