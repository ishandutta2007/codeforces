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
vector<int> q[200005];
int ans;
bool used[200005];
bool used2[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        q[a[i]].push_back(i);
    }
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    for (int i = 1; i <= 200000; ++i) if (!q[i].empty()) {
        bool t = false;
        for (int j = 1; j < (int)q[i].size(); ++j)
            if (q[i][j] != q[i][j - 1] + 1) t = true;
        if (!t) continue;
        int l = q[i][0];
        int r = q[i].back();
        while (!s.empty()) {
            set<int> :: iterator q = s.lower_bound(l);
            if (q == s.end() || *q >= r) break;
            int x = *q;
            s.erase(q);
            used[x] = true;
        }
    }
    int l = 1;
    while (l <= n) {
        if (!used[l]) {
            ++l;
            continue;
        }
        int r = l;
        vector<int> qq;
        while (r <= n && used[r]) {
            int x = a[r];
            if (!used2[x]) {
                used2[x] = true;
                qq.push_back(x);
            }
            ++r;
        }
        int mx = 0;
        for (int i = 0; i < (int)qq.size(); ++i) {
            int x = qq[i];
            int y = (int)q[x].size();
            ans += y;
            mx = max(mx, y);
        }
        ans -= mx;
        l = r;
    }
    cout << ans << '\n';
    return 0;
}