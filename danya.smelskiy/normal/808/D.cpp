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
long long a[100005];
long long p[100005];
map<long long, int> s;
long long x, y;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        x = (p[i] - (p[n] - p[i]));
        y = abs(x);
        s[a[i]] = true;
        if (i > 1 && !(y & 1ll)) {
            if (s.count(x / 2ll)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    s.clear();
    for (int i = n; i >= 1; --i) {
        x = p[n] - p[i - 1] - (p[i - 1]);
        y = abs(x);
        s[a[i]] = true;
        if (i < n && !(y & 1ll)) {
            if (s.count(x / 2ll)) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}