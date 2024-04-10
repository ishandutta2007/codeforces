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
pair<pair<int, int>, int> a[100005];
int p[100005], num[100005];
vector<int> ans[1005];
int poc[1000005];

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    int x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
                    cin >> a[i].first.first >> a[i].first.second;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            p[i] = i;
        for (int i = 2; i <= n; ++i) {
            if (a[i - 1].first.second >= a[i].first.first) {
                a[i].first.second = max(a[i].first.second, a[i - 1].first.second);
                a[i].first.first = a[i - 1].first.first;
                x = a[i- 1].second;
                y = a[i].second;
                x = get(x);
                y = get(y);
                p[x] = y;
            }
        }
        vector<int> vv;
        for (int i = 1; i <= n; ++i) if (get(i) == i) vv.push_back(i);
        for (int i = 0; i < vv.size(); ++i)
            if ((i & 1)) num[vv[i]] = 0;
            else num[vv[i]] = 1;
        ans[0].clear();
        ans[1].clear();
        for (int i = 1 ; i <= n; ++i) {
            x = a[i].second;
            x = get(x);
            ans[num[x]].push_back(a[i].second);
            poc[a[i].second] = num[x];
        }
        if (ans[0].size() == 0 || ans[1].size() == 0) {
            cout << "-1" << '\n';
            continue;
        }
        for (int i = 1; i <= n; ++i)
            cout << poc[i] + 1 << " ";
        cout << '\n';
    }
}