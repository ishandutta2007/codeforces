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
int ans = -1, pos;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int s = 0;
    for (int i = 200000; i > 0; --i) {
        if (cnt[i] == 0) {
            s = 0;
            continue;
        } else if (cnt[i] == 1) {
            if (s + 1 > ans) {
                ans = s + 1;
                pos = i;
            }
            s = cnt[i];
            if (s > ans) {
                ans = s;
                pos = i;
            }
        } else {
            s += cnt[i];
            if (s > ans) {
                ans = s;
                pos = i;
            }
        }
    }
    cout << ans << '\n';
    deque<int> q;
    for (int i = 1; i <= cnt[pos]; ++i)
        q.push_back(pos);
    for (int i = pos + 1; i <= 200000; ++i) {
        if (cnt[i] == 0) break;
        if (cnt[i] == 1) {
            q.push_back(i);
            break;
        }
        q.push_back(i);
        q.push_front(i);
        cnt[i] -= 2;
        for (int j = 1; j <= cnt[i]; ++j) {
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << '\n';
    return 0;
    
}