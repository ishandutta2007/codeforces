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


int n, m, x, y;
vector<int> v[100005];
bool used[100005];
set<int> s;

void add(int x) {
    used[x] = true;
    for (int i = 0; i < v[x].size(); ++i) {
        int to = v[x][i];
        if (!used[to]) s.insert(to);
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    add(1);
    cout << 1 << " ";
    while (!s.empty()) {
        int x = *s.begin();
        s.erase(s.begin());
        cout << x << " ";
        add(x);
    }
    cout << '\n';
}