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


pair<int, int> a[5];
pair<int, int> b[5];

bool check(int x, int y, int l, int r, int ll, int rr) {
    if (l > ll) {
        swap(l, ll);
        swap(r, rr);
    }
    if (ll <= r && l <= x && rr >= y) return true;
    return false;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        if (i) {
            if (a[i].first <= a[0].first && a[i].second <= a[0].second && b[0].first <= b[i].first && b[0].second <= b[i].second) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (a[1].first <= a[0].first && b[0].first <= b[1].first &&
        a[2].first <= a[0].first && b[0].first <= b[2].first) {
        if (check(a[0].second, b[0].second, a[1].second, b[1].second, a[2].second, b[2].second)) {
            cout << "NO\n";
            return 0;
        }
    }
    if (a[1].second <= a[0].second && b[0].second <= b[1].second &&
        a[2].second <= a[0].second && b[0].second <= b[2].second) {
        if (check(a[0].first, b[0].first, a[1].first, b[1].first, a[2].first, b[2].first)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}