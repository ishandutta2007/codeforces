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


bool used[100];

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
        for (int i = 0; i < 26; ++i)
            used[i] = false;
        for (int i = 0; i < s.size(); ++i) if (i == 0 || s[i] != s[i - 1]) {
            int l = 0;
            for (int j = i; j < s.size(); ++j) {
                if (s[j] != s[i]) break;
                ++l;
            }
            if (l & 1) used[s[i] - 'a'] = true;
        }
        string res = "";
        for (int i = 0; i < 26; ++i)
            if (used[i]) res += char(i + 'a');
        cout << res << '\n';
    }
    return 0;
}