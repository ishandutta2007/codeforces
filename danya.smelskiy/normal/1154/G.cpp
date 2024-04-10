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
const int MX = 1e7;

int n;
long long x;
int a[1000005];
int pos[10000005];
int pos1, pos2;
long long ans = 1e18;


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        if (pos[x]) {
            if (x < ans) {
                ans = x;
                pos1 = pos[x];
                pos2 = i;
            }
        }
        pos[x] = i;
    }
    long long p1, p2, cur;
    for (int i = 1; i <= MX; ++i) {
        p1 = 0, p2 = 0;
        if (pos[i]) p1 = i;
        for (int j = i + i; j <= MX; j += i) if (pos[j]) {
            if (!p1) p1 = j;
            else {
                p2 = j;
                cur = p1 * p2;
                cur /= i;
                if (cur < ans) {
                    ans = cur;
                    pos1 = pos[p1];
                    pos2 = pos[p2];
                }
                break;
            }
        }
    }
    if (pos1 > pos2) swap(pos1, pos2);
    cout << pos1 << " " << pos2 << '\n';
}