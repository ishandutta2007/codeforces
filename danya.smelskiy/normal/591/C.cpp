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
int a[500005];
vector<pair<int, pair<int, int> > > q;
int ans;


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n + 1; ++i)
        cin >> a[i];
    a[1] = a[2];
    a[n + 2] = a[n + 1];
    n += 2;
    int last = 0;
    for (int i = 1; i <= n; ++i)
        if (i == 1 || a[i] == a[i - 1]) ++last;
        else {
            if (last == 1)
            q.push_back({a[i - 1], {i - last, i - 1}});
            last = 1;
        }
    if (last == 1)
    q.push_back({a[n], {n - last + 1, n}});
    int l = 0;
    while (l < (int)q.size()) {
        int r = l + 1;
        while (r < (int)q.size() && q[r].second.first == q[r - 1].second.second + 1) ++r;
        --r;
        ans = max(ans, (r - l + 2) / 2);
        for (int i = q[l].second.first; i <= q[r].second.second; ++i) {
            if ((r - l + 1) & 1)
            a[i] = a[q[l].second.first - 1];
            else {
                int p = i - q[l].second.first + 1;
                if (p <= (r - l + 1) / 2) a[i] = a[q[l].second.first - 1];
                else a[i] = a[q[r].second.second + 1];
            }
        }
        l = r + 1;
    }
    cout << ans << '\n';
    for (int i = 2; i < n; ++i)
        cout << a[i] << " ";
    cout << '\n';
}