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
int n;
int ans;
int pos, pos2;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;
    bool t = false;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '[') {
            t = true;
            continue;
        }
        if (s[i] == ':' && t) {
            pos = i;
            break;
        }
    }
    if (!pos) {
        cout << "-1\n";
        return 0;
    }
    t = false;
    for (int i = n; i > 0; --i) {
        if (s[i] == ']') {
            t = true;
            continue;
        }
        if (s[i] == ':' && t) {
            pos2 = i;
            break;
        }
    }
    if (!pos2 || pos2 <= pos) {
        cout << "-1\n";
        return 0;
    }
    ans = 4;
    for (int i = pos + 1; i < pos2; ++i)
        if (s[i] == '|') ++ans;
    cout << ans << '\n';
}