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
int p[5005][4];
vector<int> q1;
int last;
int mt[20005];
int f[10005];
vector<pair<int, pair<int, int> > > qq1, qq2;
long long ff[10005];
long long ans;

int get(int x) {
    int res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

void update(int x) {
    while (x <= last) {
        f[x]++;
        x = (x | (x + 1));
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j)
            cin >> p[i][j];
        if (p[i][0] > p[i][2]) swap(p[i][0], p[i][2]);
        if (p[i][1] > p[i][3]) swap(p[i][1], p[i][3]);
        q1.push_back(p[i][0]);
        q1.push_back(p[i][2]);
    }
    sort(q1.begin(), q1.end());
    for (int i = 0; i < (int)q1.size(); ++i)
        if (i == 0 || q1[i] != q1[i - 1]) mt[q1[i] + 5000] = ++last;
    for (int i = 1; i <= n; ++i) {
        p[i][0] = mt[p[i][0] + 5000];
        p[i][2] = mt[p[i][2] + 5000];
        if (p[i][0] != p[i][2]) {
            qq1.push_back({p[i][1], {p[i][0], p[i][2]}});
        } else {
            qq2.push_back({p[i][3], {p[i][0], p[i][1]}});
        }
    }
    for (int i = 1; i <= 5000; ++i)
        ff[i] = (i * (i - 1)) / 2ll;
    sort(qq1.begin(), qq1.end());
    sort(qq2.begin(), qq2.end());
    long long cur;
    for (int i = 0; i < (int)qq1.size(); ++i) {
        int l = qq1[i].second.first;
        int r = qq1[i].second.second;
        int ll, rr;
        memset(f, 0, sizeof(f));
        int last = (int)qq2.size() - 1;
        for (int j = (int)qq1.size() - 1; j > i; --j) {
            ll = l;
            if (qq1[j].second.first > ll) ll = qq1[j].second.first;
            rr = r;
            if (qq1[j].second.second < rr) rr = qq1[j].second.second;
            if (ll >= rr) continue;
            while (last >= 0) {
                if (qq2[last].second.second > qq1[i].first) {
                    --last;
                    continue;
                }
                if (qq2[last].first < qq1[j].first) break;
                update(qq2[last].second.first);
                --last;
            }
            cur = get(rr) - get(ll - 1);
            ans += ff[cur];
        }
    }
    cout << ans << '\n';
    return 0;
}