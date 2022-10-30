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



int n, m;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if (x & 1) v.push_back(i);
        }
        int c = (int)v.size();
        if ((c & 1) != (m & 1) || c < m) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = c - m; i < c - 1; ++i) {
            if (i > c - m) cout << " ";
            cout << v[i];
        }
        if (c > 1) cout << " ";
        cout << n << '\n';
    }
    return 0;
}