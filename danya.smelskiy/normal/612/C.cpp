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

int ans;
char rev[300];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    stack<pair<char, char> > q;
    rev['{'] = '}';
    rev['}'] = '{';
    rev[']'] = '[';
    rev['['] = ']';
    rev[')'] = '(';
    rev['('] = ')';
    rev['>'] = '<';
    rev['<'] = '>';
    for (int i = 0; i < s.size(); ++i) {
        char tp = 'o';
        if (s[i] == '}' || s[i] == ']' || s[i] == ')' || s[i] == '>') tp = 'c';
        if (!q.empty() && q.top().first != tp && tp == 'c') {
            if (q.top().second != rev[s[i]]) ++ans;
            q.pop();
        } else q.push({tp, s[i]});
    }
    if (!q.empty()) cout << "Impossible\n";
        else cout << ans << '\n';
}