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
long long res;
int a[100005];
vector<int> v;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    res = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i > 1) {
            res += a[i] - a[i - 1];
            v.push_back(a[i] - a[i - 1] - 1);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    --k;
    for (int i = 0; i < k; ++i)
        res -= v[i];
    cout << res << '\n';
    
}