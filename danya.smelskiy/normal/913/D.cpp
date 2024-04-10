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



int n, m, ans, pos;
pair<pair<int, int>, int> a[200005];
set<pair<int, int> > s;
long long ss;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i > 0; --i) {
        s.insert(make_pair(a[i].first.second, a[i].second));
        ss += a[i].first.second;
        while (s.size() > a[i].first.first || ss > m) {
            pair<int, int> x = *s.rbegin();
            s.erase(s.find(x));
            ss -= x.first;
        }
        int x = (int)s.size();
        if (x > ans) {
            ans = x;
            pos = i;
        }
    }
    cout << ans << '\n' << ans << '\n';
    s.clear();
    ss = 0;
    for (int i = n; i >= pos; --i) {
        s.insert(make_pair(a[i].first.second, a[i].second));
        ss += a[i].first.second;
        while (s.size() > a[i].first.first || ss > m) {
            pair<int, int> x = *s.rbegin();
            s.erase(s.find(x));
            ss -= x.first;
        }
    }
    while (!s.empty()) {
        pair<int, int> x = *s.begin();
        s.erase(s.begin());
        cout << x.second << " ";
    }
    cout << '\n';
}