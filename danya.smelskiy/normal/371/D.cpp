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


int n, m, a[200005], b[200005];
set<int> s;


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(i);
    }
    cin >> m;
    while (m--) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 2) {
            cout << b[x] << '\n';
            continue;
        }
        int z;
        cin >> z;
        while (z > 0) {
            set<int> :: iterator q = s.lower_bound(x);
            if (q == s.end()) break;
            int xx = *q;
            int y = min(z, a[xx]);
            z -= y;
            a[xx] -= y;
            b[xx] += y;
            if (a[xx] == 0) {
                s.erase(q);
                continue;
            } else break;
        }
    }
}