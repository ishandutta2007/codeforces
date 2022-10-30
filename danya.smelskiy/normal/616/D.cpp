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



int n, m;
int cnt[1000005];
int a[500005];
int ans, ll, rr;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int now = 0;
    int last = 1;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        ++cnt[x];
        if (cnt[x] == 1) ++now;
        while (now > m) {
            x = a[last++];
            --cnt[x];
            if (!cnt[x]) --now;
        }
        if (i - last + 1 > ans) {
            ans = i - last + 1;
            ll = last;
            rr = i;
        }
    }
    cout << ll << " " << rr << '\n';
    
    
}