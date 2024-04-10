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
long long a[100005];
pair<int, int> b[100005];
int x, y;
long long c[100005];
long long q[100005], qq[100005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second >> c[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> x >> y;
        q[x]++;
        q[y + 1]--;
    }
    for (int i = 1; i <= m; ++i) {
        q[i] += q[i - 1];
        qq[b[i].first] += q[i] * c[i];
        qq[b[i].second + 1] -= q[i] * c[i];
    }
    for (int i = 1; i <= n; ++i) {
        qq[i] += qq[i - 1];
        if (i > 1) cout << " ";
        cout << a[i] + qq[i];
    }
    cout << '\n';
}