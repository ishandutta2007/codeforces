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
int x;
map<int, int> cnt;
set<int> s;
int a[100005];

void add(int x, int y) {
    cnt[x] += y;
    if (cnt[x] == 1) s.insert(x);
    else if (cnt[x] == 0 || cnt[x] == 2) s.erase(x);
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        add(x, 1);
        if (i > m) add(a[i - m], -1);
        if (i < m) continue;
        if (s.empty()) cout << "Nothing\n";
        else cout << *s.rbegin() << '\n';
    }
}