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


int poc;

inline bool check(int x, int y) {
    cout << "? " << x << " " << y << endl;
  //  return (x % poc >= y % poc);
    string s;
    cin >> s;
    return (bool) (s == "x");
}

inline bool test(int x) {
    return check(0, x);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    poc = 1234;
    string s;
    int x;
    while (cin >> s) {
        if (s != "start") return 0;
        x = 1;
        if (test(1)) {
            cout << "! 1" << endl;
            continue;
        }
        while (true) {
            if (!check(x + x, x)) break;
            x += x;
        }
        if (x == 1) {
            cout << "! 2" << endl;
            continue;
        }
        int l = x + 1;
        int r = x + x;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(x, mid)) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l << endl;
    }
}