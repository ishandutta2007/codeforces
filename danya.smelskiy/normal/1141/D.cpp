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
string s1, s2;
int c[100];
vector<int> v[100], v1, v2;
int c1, c2;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < (int)s1.size(); ++i) {
        if (s1[i] == '?') ++c1, v1.push_back(i);
        else ++c[s1[i] - 'a'], v[s1[i] - 'a'].push_back(i);
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < (int)s2.size(); ++i) {
        if (s2[i] == '?') ++c2, v2.push_back(i);
        else {
            int x = s2[i] - 'a';
            if (c[x]) {
                ans.push_back({v[x].back(), i});
                v[x].pop_back();
                --c[x];
            } else if (c1) {
                --c1;
                ans.push_back({v1.back(), i});
                v1.pop_back();
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        while ((int)v[i].size() > 0 && (int)v2.size() > 0) {
            ans.push_back({v[i].back(), v2.back()});
            v[i].pop_back();
            v2.pop_back();
        }
    }
    while ((int)v1.size() > 0 && (int)v2.size() > 0) {
        ans.push_back({v1.back(), v2.back()});
        v1.pop_back();
        v2.pop_back();
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i].first + 1 << " " << ans[i].second + 1<< '\n';
    return 0;
}