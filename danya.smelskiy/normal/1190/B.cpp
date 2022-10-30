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
int a[100005];
long long s;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    if (s == 0) {
        cout << "cslnb\n";
        return 0;
    }
    if (n == 1) {
        cout << (a[1] % 2 == 1 ? "sjfnb" : "cslnb") << '\n';
        return 0;
    }
    sort(a + 1, a + n + 1);
    vector<int> pos;
    for (int i = 2; i <= n; ++i)
        if (a[i] == a[i - 1]) pos.push_back(i);
    if ((int)pos.size() > 1) {
        cout << "cslnb\n";
        return 0;
    }
    long long it = 0;
    if ((int)pos.size() == 1) {
        int x = pos[0];
        if (a[x] == 0) {
            cout << "cslnb\n";
            return 0;
        }
        --a[x - 1];
        it = 1;
        if (x > 2 && a[x - 2] == a[x - 1]) {
            cout << "cslnb\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i] -= i - 1;
        it += a[i];
    }
    if (it % 2ll == 1ll) cout << "sjfnb\n";
    else cout << "cslnb\n";
    return 0;
}