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


int n, m, ss;
int ans[100005];
pair<int, int> a[100005];
pair<pair<int, int>, int> b[100005];
int cnt[100005];


bool f(int mid) {
    set<pair<int, int> > s;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
    }
    int last = n;
    set<pair<int, int> > :: iterator q;
    long long res = 0;
    for (int i = m; i > 0; --i) {
        while (last > 0 && b[last].first.first >= a[i].first) {
            s.insert({b[last].first.second, b[last].second});
            --last;
        }
        if (s.empty()) return false;
        q = s.begin();
        pair<int, int> xx = *q;
        s.erase(q);
        res += xx.first;
        ans[a[i].second] = xx.second;
        xx.first = 0;
        ++cnt[xx.second];
        if (cnt[xx.second] < mid) s.insert(xx);
    }
    return (bool)(res <= ss);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> ss;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= n; ++i)
        cin >> b[i].first.first;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i].first.second;
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    int l = 1;
    int r = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    if (!f(l)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " ";
    cout << '\n';
}