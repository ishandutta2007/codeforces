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
        int n;
        string s;
        cin >> n;
        cin >> s;
        int last = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'P') ++last;
            else last = 0;
            if (last != i + 1) ans = max(ans, last);
        }
        cout << ans << '\n';
    }
    return 0;
}