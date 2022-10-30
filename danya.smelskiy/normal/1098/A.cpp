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
vector<int> v[100005];
long long a[100005];
long long ans[100005];



void dfs(int x, int y, int d) {
    if (d % 2 == 0) {
        if (v[x].size() == 0) {
            ans[x] = 0;
            a[x] = a[y];
            return;
        }
        long long cur = 1e9;
        for (int j = 0; j < v[x].size(); ++j) {
            int to = v[x][j];
            cur = min(cur, a[to] - a[y]);
        }
        if (cur < 0) {
            cout << "-1\n";
            exit(0);
        }
        ans[x] = cur;
        a[x] = a[y] + cur;
        for (int i = 0;i < v[x].size(); ++i) {
            int to = v[x][i];
            dfs(to, x, d + 1);
        }
        return;
    }
    ans[x] = a[x] - a[y];
    if (ans[x] < 0) {
        cout << "-1\n";
        exit(0);
    }
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        dfs(to, x, d + 1);
    }
    return;
}

int main(int argc, const char * argv[]) {
    //    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        v[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0, 1);
    long long res = 0;
    for (int i = 1; i <= n; ++i) if (ans[i] < 0) {
        cout << "-1\n";
        exit(0);
    } else res += ans[i];
    cout << res << '\n';
    return 0;
}

//1.74279e-09