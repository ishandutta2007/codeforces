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
# define int long long
using namespace std;



int n, x, y;
vector<pair<int, int> > v, vv;
int cnt[200005];

main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        v.push_back(make_pair(x, -1));
        v.push_back(make_pair(y + 1, 1));
    }
    sort(v.begin(), v.end());
    vector<pair<int, int> > vv;
    for (int i = 0; i < v.size(); ++i) {
        if (i + 1 < v.size() && v[i].first == v[i + 1].first) v[i + 1].second += v[i].second;
        else {
            vv.push_back(v[i]);
        }
    }
    int last = 0;
    for (int i = 0; i < vv.size(); ++i) {
        if (i) {
            cnt[last] += vv[i].first - vv[i - 1].first;
        }
        last -= vv[i].second;
    }
    for (int i = 1; i <= n; ++i)
        cout << cnt[i] << " ";
    cout << '\n';
    
    
}