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
set<pair<int, int> > s;
vector<pair<pair<int, int>, int> > ans;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        ++last;
        if (i == n || a[i] != a[i + 1]) {
            s.insert({last, a[i]});
            last = 0;
        }
    }
    while (s.size() > 2) {
        set<pair<int, int> > :: iterator q1, q2, q3;
        q1 = s.end();
        --q1;
        q2 = q1;
        --q2;
        q3 = q2;
        --q3;
        pair<int, int> xx = *q1, yy = *q2, zz = *q3;
        s.erase(q1);
        s.erase(q2);
        s.erase(q3);
        --xx.first;
        --yy.first;
        --zz.first;
        if (xx.first) s.insert(xx);
        if (yy.first) s.insert(yy);
        if (zz.first) s.insert(zz);
        int x2 = xx.second;
        int x3 = yy.second;
        int x4 = zz.second;
        if (x2 < x3) swap(x2, x3);
        if (x3 < x4) swap(x3, x4);
        if (x2 < x3) swap(x2, x3);
        ans.push_back({{x2, x3}, x4});
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << '\n';
}