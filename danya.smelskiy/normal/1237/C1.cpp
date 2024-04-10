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
pair<pair<int ,int>, pair<int ,int> > a[100005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second.first;
        a[i].second.second = i;
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    int last = 0;
    while (l <= n) {
        int r = l;
        while (r <= n && a[l].first.first == a[r].first.first) ++r;
        --r;
        int ll = l;
        vector<int> q;
        while (ll <= r) {
            if (ll < r && a[ll].first.second == a[ll + 1].first.second) {
                cout << a[ll].second.second << " " << a[ll + 1].second.second << '\n';
                ll += 2;
            } else {
                q.push_back(ll);
                ++ll;
            }
        }
        while (q.size() >= 2) {
            int x = q.back();
            q.pop_back();
            int y = q.back();
            q.pop_back();
            cout << a[x].second.second << " " << a[y].second.second << '\n';
        }
        if (!q.empty()) {
            int x = q[0];
            if (last != 0) {
                cout << last << " " << a[x].second.second << '\n';
                last = 0;
            } else last = a[x].second.second;
        }
        l = r + 1;
    }
    return 0;
}