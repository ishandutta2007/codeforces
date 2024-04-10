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
# define int long long
using namespace std;


int n, m;
pair<int, int> a[200005], b[200005];
vector<pair<pair<int, int>, int> > v;
int ans[200005];

main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i < n; ++i) {
        int ll = a[i + 1].first - a[i].second;
        int rr = a[i + 1].second - a[i].first;
        v.push_back({{ll, rr}, i});
    }
    sort(v.begin(), v.end());
    int last = 0;
    set<pair<int, int> > s;
    for (int i = 1; i <= m; ++i) {
        while (last < v.size() && v[last].first.first <= b[i].first) {
            s.insert({v[last].first.second, v[last].second});
            ++last;
        }
        if (!s.empty()) {
            pair<int, int> xx = *s.begin();
            s.erase(xx);
            if (xx.first < b[i].first) {
                cout << "No\n";
                return 0;
            }
            ans[xx.second] = b[i].second;
        }
    }
    if (!s.empty() || last < v.size()) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 1; i < n; ++i)
        cout << ans[i] << " ";
    cout << '\n';

}