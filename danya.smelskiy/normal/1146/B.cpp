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
int c1, c2;
string ss;
string ss2;

void no() {
    cout << ":(\n";
    exit(0);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i)
        if (s[i] == 'a') ++c1;
        else ++c2;
    if ((c2 & 1)) no();
    for (int i = 0; i < (int)s.size() - c2 / 2; ++i)
        ss += s[i];
    string ss2 = ss;
    for (int i = 0; i < (int)ss.size(); ++i)
        if (ss[i] != 'a') ss2 += ss[i];
    if (ss2 != s) no();
    else cout << ss << '\n';
        
}