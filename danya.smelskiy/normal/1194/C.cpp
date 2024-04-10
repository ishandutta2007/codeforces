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


int cnt[100];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t, p;
        cin >> s >> t >> p;
        int last = 0;
        for (int i = 0; i < (int)t.size(); ++i) {
            if (last < (int)s.size() && s[last] == t[i]) ++last;
        }
        if (last != (int)s.size()) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < 26; ++i)
            cnt[i] = 0;
        for (int i = 0; i < (int)t.size(); ++i)
            ++cnt[t[i] - 'a'];
        for (int i = 0; i < (int)s.size(); ++i)
            --cnt[s[i] - 'a'];
        int res = (int)t.size() - (int)s.size();
        for (int i = 0; i < (int)p.size(); ++i) {
            int x = p[i] - 'a';
            if (cnt[x]) {
                --cnt[x];
                --res;
            }
        }
        if (res != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}