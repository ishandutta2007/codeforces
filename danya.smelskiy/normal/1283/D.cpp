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
int x;
map<int, bool> used;
set<pair<int, pair<int, bool> > > s;

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        used[x] = true;
        s.insert({1, {x - 1, 0}});
        s.insert({1, {x + 1, 1}});
    }
    long long ans = 0;
    vector<int> v;
    while (m) {
        int x = s.begin()->second.first;
        int y = s.begin()->second.second;
        int cur = s.begin()->first;
        s.erase(s.begin());
        if (used[x]) continue;
        --m;
        ans += cur;
        used[x] = true;
        v.push_back(x);
        if (y) ++x;
        else --x;
        if (!used.count(x)) s.insert({cur + 1, {x, y}});
    }
    cout << ans << '\n';
    for (int i = 0; i < v.size(); ++i) {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << '\n';
    return 0;
}