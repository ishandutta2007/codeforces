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
set<pair<pair<int, int>, int> > s;
int dist[100005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        if (m & 1) dist[i] = abs((m + 1) / 2 - i);
        else if (i <= m / 2) dist[i] = (m / 2) - i + 1;
        else dist[i] = i - (m / 2);
        s.insert({{0, dist[i]}, i});
    }
    while (n--) {
        pair<pair<int, int>, int> x = *s.begin();
        s.erase(s.begin());
        ++x.first.first;
        cout << x.second << '\n';
        s.insert(x);
    }
    
}