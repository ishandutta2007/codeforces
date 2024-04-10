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
string s;
int ans[200005];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int pos = -1;
        for (int i = 1; i < n; ++i)
            if (s[i - 1] > s[i]) {
                pos = i;
                break;
            }
        if (pos == -1) {
            for (int i = 1; i <= n; ++i)
                cout << "1";
            cout << '\n';
            continue;
        }
        vector<pair<char, int> > v1, v2;
        v1.push_back({s[pos], pos});
        bool ch = false;
        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] <= v1.back().first) v1.push_back({s[i], i});
            else if (v2.empty() || s[i] <= v2.back().first) v2.push_back({s[i], i});
            else {
                ch = true;
                break;
            }
        }
        if (ch) {
            cout << "-\n";
            continue;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        for (int i = pos + 1; i < n; ++i) {
            char x = v1.back().first;
            char y = v2.back().first;
            if (x <= s[i] && y <= s[i]) {
                if (x >= y) v1.push_back({s[i], i});
                else v2.push_back({s[i], i});
            } else if (x <= s[i]) v1.push_back({s[i], i});
            else if (y <= s[i]) v2.push_back({s[i], i});
            else {
                ch = true;
                break;
            }
        }
        if (v1.back().first > v2[0].first) {
            ch = true;
        }
        if (ch) {
            cout << "-\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            ans[i] = 2;
        for (int i = 0; i < (int)v1.size(); ++i)
            ans[v1[i].second] = 1;
        for (int i = 0; i < n; ++i)
            cout << ans[i];
        cout << '\n';
    }
    return 0;
}