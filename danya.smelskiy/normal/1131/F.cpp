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
int p[200005];
vector<int> v[200005];

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        v[i].push_back(i);
    }
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        x = get(x);
        y = get(y);
        if ((int)v[x].size() > (int)v[y].size()) swap(x, y);
        p[x] = y;
        for (int j = 0; j < (int)v[x].size(); ++j)
            v[y].push_back(v[x][j]);
    }
    x = get(1);
    for (int i = 0; i < (int)v[x].size(); ++i)
        cout << v[x][i] << " ";
    cout << '\n';
}