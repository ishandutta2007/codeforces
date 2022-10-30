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
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<int> s;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            s.insert(x);
        }
        bool ans = false;
        while (!s.empty()) {
            int x = *s.begin();
            s.erase(s.find(x));
            if (x == 2048) ans = true;
            if (s.empty()) break;
            int y = *s.begin();
            if (x != y) continue;
            s.erase(s.find(y));
            x += y;
            s.insert(x);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}