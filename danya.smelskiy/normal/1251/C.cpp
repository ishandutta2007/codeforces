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
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> v1, v2;
        for (int i = 0; i < s.size(); ++i) {
            int x = s[i] - '0';
            if ((x & 1)) v1.push_back(x);
            else v2.push_back(x);
        }
        string res = "";
        int l = 0;
        int r = 0;
        while (l < v1.size() || r < v2.size()) {
            if (r == v2.size() || (l < v1.size() && v1[l] < v2[r])) {
                res += char(v1[l++] + '0');
            } else {
                res += char(v2[r++] + '0');
            }
        }
        cout << res << '\n';
    }
    return 0;
}