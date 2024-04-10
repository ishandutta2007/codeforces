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
multiset<int> s;
map<int, int> m;
vector<int> ans;

bool f(int mid) {
    s.clear();
    m.clear();
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        while (x > mid) x >>= 1;
        s.insert(x);
    }
    ans.clear();
    while (!s.empty()) {
        int x = *s.rbegin();
        s.erase(s.find(x));
        if (x > mid || m[x]) {
            if (x == 1) return false;
            x >>= 1;
            s.insert(x);
            continue;
        } else {
            m[x] = true;
            ans.push_back(x);
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1;
    int r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    f(l);
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';
    
}