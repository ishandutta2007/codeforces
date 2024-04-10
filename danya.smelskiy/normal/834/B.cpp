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
string s;
int last[10005];
bool op[10005];


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = s.size() - 1; i > 0; --i) {
        if (!last[s[i]]) last[s[i]] = i;
    }
    int cur = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!op[s[i]]) {
            op[s[i]] = true;
            ++cur;
        }
        if (cur > m) {
            cout << "YES\n";
            return 0;
        }
        if (last[s[i]] == i) --cur;
    }
    cout << "NO\n";
}