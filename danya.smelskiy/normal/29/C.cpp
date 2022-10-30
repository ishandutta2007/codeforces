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


int n, x, y;
map<int, int> mt;
int outmt[100005];
int all;
vector<int> v[100005];

void dfs(int x, int y = 0) {
    cout << outmt[x] << " ";
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (to != y) dfs(to, x);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (!mt[x]) {
            mt[x] = ++all;
            outmt[all] = x;
        }
        x = mt[x];
        if (!mt[y]) {
            mt[y] = ++all;
            outmt[all] = y;
        }
        y = mt[y];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int pos = 0;
    for (int i = 1; i <= all; ++i)
        if (v[i].size() == 1) {
            pos = i;
            break;
        }
    dfs(pos);
    cout << '\n';
    return 0;
}