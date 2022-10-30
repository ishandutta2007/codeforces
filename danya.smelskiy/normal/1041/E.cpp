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


int n, x, y;
int cnt[1005];
vector<int> q;
vector<pair<int, int> > ans;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        if (y != n) {
            cout << "NO\n";
            return 0;
        }
        ++cnt[x];
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            q.push_back(i);
            continue;
        }
        int last = n;
        while (cnt[i] > 1) {
            if (q.size() == 0) {
                cout << "NO\n";
                return 0;
            }
            ans.push_back({last, q.back()});
            last = q.back();
            q.pop_back();
            --cnt[i];
        }
        ans.push_back({last, i});
    }
    cout << "YES\n";
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    
}