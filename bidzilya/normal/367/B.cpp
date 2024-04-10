#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 2e5 + 100;

int n, m, p;
int a[max_n];
map<int, int> mb, ma;
vector<int> ans;
int cg, cb;

void update(int x, int d) {
    int pz = ma[x];
    int nz = pz + d;
    if (mb.find(x) == mb.end()) {
        if (nz == 0) {
            --cb;
        }
        if (pz == 0) {
            ++cb;
        }
    } else {
        int z = mb[x];
        if (nz == z) {
            ++cg;
        } else if (pz == z) {
            --cg;
        }
    }
    if (nz == 0) {
        ma.erase(x);
    } else {
        ma[x] = nz;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ++mb[x];
    }
    int sz = mb.size();
    for (int i = 0; i < min(n, p); ++i) {
        cg = 0;
        cb = 0;
        ma.clear();
        for (int j = i; j < n; j += p) {
            ll k = j - 1LL * m * p;
            if (k >= 0) update(a[k], -1);
            update(a[j], 1);
            if (cg == sz && cb == 0) {
                ans.push_back(j - (m - 1) * p + 1);
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}