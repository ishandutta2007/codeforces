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

vector<int> q1[100], q2[100];

void solve(int l, int r, int x) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    for (int i = l; i <= r; ++i)
        if (i <= mid) q1[x].push_back(i);
        else q2[x].push_back(i);
    solve(l, mid, x + 1);
    solve(mid + 1, r, x + 1);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = -1;
        for (int i = 1; i <= 9; ++i)
            q1[i].clear(), q2[i].clear();
        solve(1, n, 1);
        for (int i = 1; i <= 9; ++i) if ((int)q1[i].size() > 0 && (int)q2[i].size() > 0) {
            cout << (int)q1[i].size() << " " << (int)q2[i].size();
            for (int j = 0; j < (int)q1[i].size(); ++j)
                cout << " " << q1[i][j];
            for (int j = 0; j < (int)q2[i].size(); ++j)
                cout << " " << q2[i][j];
            cout << endl;
            int res = 0;
            cin >> res;
            ans = max(ans, res);
        }
        cout << "-1 " << ans << endl;
    }
    
}