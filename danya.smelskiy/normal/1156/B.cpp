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

string s;
int cnt[100];


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        for (int i = 0; i < 26; ++i)
            cnt[i] = 0;
        for (int i = 0; i < (int)s.size(); ++i)
            ++cnt[s[i] - 'a'];
        vector<pair<int, int> > v;
        for (int i = 0; i < 26; ++i)
            if (cnt[i]) v.push_back(make_pair(i, cnt[i]));
        if ((int)v.size() == 1) {
            cout << s << '\n';
            continue;
        }
        if ((int)v.size() == 2) {
            if (v[1].first == v[0].first + 1) {
                cout << "No answer\n";
                continue;
            }
            cout << s << '\n';
            continue;
        }
        if ((int)v.size() == 3) {
            if (v[2].first == v[1].first + 1 && v[1].first == v[0].first + 1) {
                cout << "No answer\n";
                continue;
            }
            if (v[1].first - v[0].first == 1) {
                swap(v[2], v[1]);
            } else if (v[2].first - v[1].first == 1) {
                swap(v[0], v[1]);
            }
            int x, y;
            for (int i = 0; i < (int)v.size(); ++i) {
                x = v[i].first;
                y = v[i].second;
                for (int i = 1; i <= y; ++i)
                    cout << char(x + 'a');
            }
            cout << '\n';
            continue;
        }
        string res = "";
        int l = 0;
        int r = ((int)v.size()) / 2;
        int ll = r;
        while (l < ll) {
            int x = v[r].first;
            int y = v[r].second;
            for (int i = 1; i <= y; ++i)
                cout << char(x + 'a');
            x = v[l].first;
            y = v[l].second;
            for (int i = 1; i <= y; ++i)
                cout << char(x + 'a');
            ++l;
            ++r;
        }
        if (r < (int)v.size()) {
            int x = v[r].first;
            int y = v[r].second;
            for (int i = 1; i <= y; ++i)
                cout << char(x + 'a');
        }
        cout << '\n';
    }
    return 0;
}