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
vector<pair<int, int> > v1, v2;

void prnt(char c, vector<pair<int, int> > v, int m) {
    reverse(v.begin(), v.end());
    if (c == 'B') {
        for (int i = 0; i < v.size() && i < m; ++i)
            cout << c << " " << v[i].first << " " << v[i].second << '\n';
        return;
    }
    vector<pair<int, int> > vv;
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size() && i < m; ++i)
        vv.push_back(v[i]);
    reverse(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); ++i)
        cout << c << " " << vv[i].first << " " << vv[i].second << '\n';
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        int x, y;
        if (c == 'S') {
            cin >> x >> y;
            v1.push_back(make_pair(x, y));
        } else {
            cin >> x >> y;
            v2.push_back(make_pair(x, y));
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<pair<int, int> > vv;
    for (int i = 1; i < v1.size(); ++i) {
        if (v1[i].first == v1[i - 1].first) v1[i].second += v1[i - 1].second;
    }
    for (int i = 0; i < v1.size(); ++i)
        if (i == (int)v1.size() - 1 || v1[i].first != v1[i + 1].first) vv.push_back(v1[i]);
    v1 = vv;
    vv.clear();
    for (int i = 1; i < v2.size(); ++i) {
        if (v2[i].first == v2[i - 1].first) v2[i].second += v2[i - 1].second;
    }
    for (int i = 0; i < v2.size(); ++i)
        if (i == (int)v2.size() - 1 || v2[i].first != v2[i + 1].first) vv.push_back(v2[i]);
    v2 = vv;
    prnt('S', v1, m);
    prnt('B', v2, m);
    
}