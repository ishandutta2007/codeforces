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
vector<int> v[1005];
int cnt[1005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n ;++i) {
        v[s[i - 1] - 'a'].push_back(i);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j)
            cnt[j] = 0;
        int res = 0;
        cin >> s;
        for (int j = 0; j < (int)s.size(); ++j) {
            int x = s[j] - 'a';
            res = max(res, v[x][cnt[x]]);
            ++cnt[x];
        }
        cout << res << '\n';
    }
    return 0;
}