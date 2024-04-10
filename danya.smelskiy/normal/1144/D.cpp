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
int a[200005];
int cnt[200005];
int pos, mx = -1;


int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        if (cnt[a[i]] > mx) {
            mx = cnt[a[i]];
            pos = a[i];
        }
    }
    cout << n - mx << '\n';
    for (int i = 1; i <= n; ++i) if (a[i] == pos) {
        for (int j = i - 1; j > 0; --j) {
            if (a[j] > pos) {
                cout << 2 << " " << j << " " << j + 1 << '\n';
                a[j] = pos;
            } else if (a[j] < pos) {
                cout << 1 << " " << j << " " << j + 1 << '\n';
                a[j] = pos;
            }
        }
        break;
    }
    for (int i = 2; i <= n; ++i)
        if (a[i] != pos) {
            if (a[i] > pos) cout << 2 << " ";
            else cout << 1 << " ";
            cout << i << " " << i - 1 << '\n';
        }
    
    return 0;
}