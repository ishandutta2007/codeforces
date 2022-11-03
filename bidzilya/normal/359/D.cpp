#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

typedef long long ll;

const int max_n = 3e5 + 100;
const int max_ai = 1e6 + 100;

int n;
int a[max_n];
int lb[max_n], rb[max_n];

int gcd(int x, int y) {
    while (x > 0 && y > 0)
        if (x >= y)
            x %= y;
        else
            y %= x;
    return x + y;
}

struct SparseTable {

    int n;
    vector<vector<int> > table;
    vector<int> max_log;

    void build(int _n, int* a) {
        n = _n;
        max_log.resize(n + 1);
        max_log[1] = 0;
        for (int i = 2; i <= n; ++i) {
            max_log[i] = max_log[i - 1];
            if ((1 << (max_log[i] + 1)) <= i)
                ++max_log[i];
        }
        table.resize(n);
        for (int i = 0; i < n; ++i)
            table[i].resize(max_log[n] + 1);
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int st = 1; st <= max_log[n]; ++st)
            for (int j = 0; j < n; ++j) {
                table[j][st] = table[j][st - 1];
                if (j + (1 << (st - 1)) < n)
                    table[j][st] = gcd(table[j][st], table[j + (1 << (st - 1))][st - 1]);
            }
    }
    
    int gcd_query(int l, int r) {
        int st = max_log[r - l + 1];
        return gcd(table[l][st], table[r - (1 << st) + 1][st]);
    }
};

SparseTable table;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    table.build(n, a);
    for (int i = 0; i < n; ++i) {
        lb[i] = rb[i] = i;
        int sl = 1, sr = i + 1;
        while (sl <= sr) {
            int ml = (sl + sr) >> 1;
            if (table.gcd_query(i - ml + 1, i) == a[i]) {
                lb[i] = i - ml + 1;
                sl = ml + 1;
            } else {
                sr = ml - 1;
            }
        }
        sl = 1, sr = n - i;
        while (sl <= sr) {
            int ml = (sl + sr) >> 1;
            if (table.gcd_query(i, i + ml - 1) == a[i]) {
                rb[i] = i + ml - 1;
                sl = ml + 1;
            } else {
                sr = ml - 1;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
        ans = max(ans, rb[i] - lb[i] + 1);
    vector<int> zans;
    for (int i = 0; i < n; ++i)
        if (rb[i] - lb[i] + 1 == ans) 
            zans.push_back(lb[i]);
    sort(zans.begin(), zans.end());
    vector<int> wans;
    wans.push_back(zans[0]);
    for (int i = 1; i < (int) zans.size(); ++i)
        if (zans[i] != wans[wans.size() - 1]) {
            wans.push_back(zans[i]);
        }
    cout << wans.size() << " " << ans - 1 << endl;
    for (int i = 0; i < (int) wans.size(); ++i)
        cout << wans[i] + 1 << " ";
    cout << endl;
    return 0;
}