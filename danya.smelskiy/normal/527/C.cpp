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


int w, h, n;

set<int> s[2];
multiset<int> ss[2];

void Split(int x, int y) {
    set<int> :: iterator q = s[x].lower_bound(y);
    set<int> :: iterator qq = q;
    --qq;
    ss[x].erase(ss[x].find((*q) - (*qq)));
    s[x].insert(y);
    ss[x].insert((*q) - y);
    ss[x].insert(y - (*qq));
    return;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> w >> h >> n;
    s[0].insert(0);
    s[0].insert(w);
    s[1].insert(0);
    s[1].insert(h);
    ss[0].insert(w);
    ss[1].insert(h);
    while (n--) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == 'H') Split(1, x);
        else Split(0, x);
        cout << (*ss[0].rbegin()) * 1ll * (*ss[1].rbegin()) << '\n';
    }
}