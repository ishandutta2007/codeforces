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
int x, y;
vector<pair<int, pair<int, int> > > e;
pair<int, int> a[200005];





int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        e.push_back({x, {0, i}});
        e.push_back({y, {1, i}});
        a[i] = {x, y};
    }
    sort(e.begin(), e.end());
    set<pair<int, int > > s;
    vector<int> ans;
    for (int i = 0; i < e.size(); ++i) {
        if (e[i].second.first == 0) {
            int x = e[i].second.second;
            s.insert({a[x].second, x});
        } else {
            int x = e[i].second.second;
            s.erase({a[x].second, x});
        }
            while (s.size() > m) {
                pair<int, int> x = *s.rbegin();
                s.erase(x);
                ans.push_back(x.second);
            }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << " ";
    cout << '\n';
    return 0;
}