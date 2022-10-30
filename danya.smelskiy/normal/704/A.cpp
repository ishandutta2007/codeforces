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
int tp, x, all, ans;
vector<int> v[300005];
bool used[300005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int last = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            ++all;
            ++ans;
            v[x].push_back(all);
        } else if (tp == 2) {
            cin >> x;
            for (int i = 0; i < v[x].size(); ++i) {
                int to = v[x][i];
                if (!used[to]) --ans;
                used[to] = true;
            }
            v[x].clear();
        } else {
            cin >> x;
            while (last <= x) {
                if (!used[last]) {
                    used[last] = true;
                    --ans;
                }
                ++last;
            }
        }
        cout << ans << '\n';
    }
}