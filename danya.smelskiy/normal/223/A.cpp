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
stack<pair<char,int > > q;
int p[100005];
int ans;
int l = 1, r = 0;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    s = "#" + s;
    n = (int)s.size() - 1;
    q.push({'0', 0});
    string ss = s;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1];
        if (s[i] == '[') ++p[i];
        if (s[i] == '(' || s[i] == '[') q.push({s[i], i});
        else {
            if (s[i] == ')') s[i] = '(';
            else if (s[i] == ']') s[i] = '[';
            if (!q.empty() && q.top().first == s[i]) q.pop();
            else q.push({ss[i], i});
        }
        int last = q.top().second;
        if (p[i] - p[last] > ans) {
            ans = p[i] - p[last];
            l = last + 1;
            r = i;
        }
    }
    cout << ans << '\n';
    if (l < r) {
        for (int i = l; i <= r; ++i) {
            cout << ss[i];
        }
        cout << '\n';
    }
}