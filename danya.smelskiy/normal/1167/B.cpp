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


int ans[100];


inline int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
 //   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a[] = {4, 8, 15, 16, 23, 42};
    int x = ask(1, 6);
    int y = ask(1, 5);
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 6; ++j)
            if (i != j) {
                for (int k = 1; k <= 6; ++k) if (k != i && k != j) {
                    int xx = a[i - 1] * a[j - 1];
                    int yy = a[i - 1] * a[k - 1];
                    if (xx == x && yy == y) {
                        ans[1] = a[i - 1];
                        ans[5] = a[k - 1];
                        ans[6] = a[j - 1];
                    }
                }
            }
    x = ask(2, 3);
    y = ask(2, 4);
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 6; ++j)
            if (i != j) {
                for (int k = 1; k <= 6; ++k) if (k != i && k != j) {
                    int xx = a[i - 1] * a[j - 1];
                    int yy = a[i - 1] * a[k - 1];
                    if (xx == x && yy == y) {
                        ans[2] = a[i - 1];
                        ans[4] = a[k - 1];
                        ans[3] = a[j - 1];
                    }
                }
            }
    cout << "! ";
    for (int i = 1; i <= 6; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}