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
int a[200005];
int pos[200005];
bool used[200005];
int ans[200005];
set<int> s;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(i);
        pos[a[i]] = i;
    }
    for (int i = n, it = 0; i > 0; --i) if (!used[i]) {
        ++it;
        if (it > 2) it = 1;
        used[i] = true;
        ans[i] = it;
        int x = pos[i];
        s.erase(x);
        for (int j = 1; j <= m; ++j) {
            set<int> :: iterator q = s.lower_bound(x);
            if (q == s.end()) break;
            int y = *q;
            used[a[y]] = true;
            ans[a[y]] = it;
            s.erase(y);
        }
        for (int j = 1; j <= m; ++j) {
            set<int> :: iterator q = s.lower_bound(x);
            if (q == s.begin()) break;
            --q;
            int y = *q;
            if (y >= x) break;
            used[a[y]] = true;
            ans[a[y]] = it;
            s.erase(y);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[a[i]];
    cout << '\n';
}