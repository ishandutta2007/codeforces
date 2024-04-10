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



int n, m, k;
int a[1005][1005];
int num1[1005], num2[1005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        num1[i] = i;
        for (int j = 1; j <= m; ++j) {
            num2[j] = j;
            cin >> a[i][j];
        }
    }
    while (k--) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'c') swap(num2[x], num2[y]);
        else if (c == 'r') swap(num1[x], num1[y]);
        else cout << a[num1[x]][num2[y]] << '\n';
    }
}