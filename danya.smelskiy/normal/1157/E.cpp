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
int a[200005];
int x;
multiset<int> s;

inline int get_min(int x) {
    multiset<int> :: iterator q = s.lower_bound(n - x);
    if (q == s.end()) --q;
    return *q;
}


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        s.insert(x);
    }
    int y, z;
    for (int i = 1; i <= n; ++i) {
        x = a[i];
        y = *s.begin();
        z = get_min(x);
        if ((x + y) % n <= (x + z) % n) {
            s.erase(s.find(y));
            cout << (x + y) % n << " ";
        } else {
            s.erase(s.find(z));
            cout << (x + z) % n << " ";
        }
    }
    cout << '\n';
    return 0;
}