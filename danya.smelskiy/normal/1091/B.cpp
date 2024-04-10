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
int ans1, ans2;
pair<int, int> a[100005], b[100005];


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1;i <= n ;++i) {
        cin >> b[i].first >> b[i].second;
    }
    ans1 = a[1].first, ans2 = b[1].first;
    for (int i = 1;i <= n; ++i) {
        ans1 = max(ans1, a[i].first);
        ans2 = min(ans2, b[i].first);
    }
    cout << ans1 + ans2 << " ";
    ans1 = a[1].second;
    ans2 = b[1].second;
    for (int i = 1;i <= n; ++i) {
        ans1 = max(ans1, a[i].second);
        ans2 = min(ans2, b[i].second);
    }
    cout << ans1 + ans2 << endl;
}