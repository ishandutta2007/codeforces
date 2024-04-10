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
vector<int> v[200005];
int clr[200005];
int x, y;
vector<int> ans[2000];
bool used[200005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            v[i].clear();
            clr[i] = 0;
            used[i] = false;
        }
        for (int i = 1; i <= m; ++i) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> q;
        q.push_back(1);
        used[1] = true;
        ans[0].clear();
        ans[1].clear();
        for (int i = 0; i < (int)q.size(); ++i) {
            int x = q[i];
            ans[clr[x]].push_back(x);
            for (int j = 0; j < (int)v[x].size(); ++j) {
                int to = v[x][j];
                if (!used[to]) {
                    used[to] = true;
                    q.push_back(to);
                    clr[to] = 1 - clr[x];
                }
            }
        }
        if ((int)ans[0].size() > (int)ans[1].size()) swap(ans[0], ans[1]);
        cout << (int)ans[0].size() << '\n';
        for (int i = 0; i < (int)ans[0].size(); ++i)
            cout << ans[0][i] << " ";
        cout << '\n';
    }
    return 0;
}