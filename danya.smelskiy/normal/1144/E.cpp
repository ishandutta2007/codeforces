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
int c[200005];



int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    for (int i = n; i > 0; --i) {
        c[i] += (s1[i - 1] - 'a') + (s2[i - 1] - 'a');
        if (c[i] >= 26) {
            c[i] -= 26;
            c[i - 1]++;
        }
    }
    for (int i = 0; i <= n; ++i)
        if (c[i] & 1) {
            c[i]--;
            c[i + 1] += 26;
            c[i] /= 2;
        } else c[i] /= 2;

    for (int i = 1; i <= n; ++i)
        cout << char('a' + c[i]);
    cout << '\n';
}