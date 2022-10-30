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
set<int> ss[100];
int m;

int solve(int l, int r) {
    set<int> :: iterator q;
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        q = ss[i].lower_bound(l);
        if (q != ss[i].end() && *q <= r) {
            ++res;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        ss[s[i] - 'a'].insert(i);
    }
    cin >> m;
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            --pos;
            ss[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            ss[s[pos] - 'a'].insert(pos);
        } else {
            int l, r;
            cin >> l >> r;
            cout << solve(l - 1, r - 1) << '\n';
        }
    }
    return 0;
}