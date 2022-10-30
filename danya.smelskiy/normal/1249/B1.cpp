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
int all;
int ans[200005];
bool used[200005];
vector<int> q;
int a[200005];

void dfs(int x) {
    used[x] = true;
    ++all;
    q.push_back(x);
    int to = a[x];
    if (!used[to]) dfs(to);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            used[i] = false;
        }
        for (int i = 1; i <= n; ++i)
            if (!used[i]) {
                all = 0;
                q.clear();
                dfs(i);
                for (auto it : q)
                    ans[it] = all;
            }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}