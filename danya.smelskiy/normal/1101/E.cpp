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
int x, y;
char c;

int mx1, mx2;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> c;
        if (c == '+') {
            cin >> x >> y;
            if (x > y) swap(x, y);
            if (x > mx1) mx1 = x;
            if (y > mx2) mx2 = y;
        } else {
            cin >> x >> y;
            if (x > y) swap(x, y);
            if (x < mx1 || y < mx2) cout << "NO\n";
            else cout <<"YES\n";
        }
    }
}