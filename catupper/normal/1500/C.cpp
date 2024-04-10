#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define PRIM 3
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int my_hash(vector<int> &x)
{
    Int h = 123021123;
    for (auto e : x) {
        h = (h * 814805291 + e) % 1000000003;
    }
    return h;
}

Int dict[1500];
bool used[1500];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
        dict[i] = my_hash(a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
        auto h = my_hash(b[i]);
        bool done = false;
        for (int j = 0; j < n; j++) {
            if (!used[j] && dict[j] == h) {
                b[i].push_back(j);
                used[j] = true;
                done = true;
                break;
            }
        }
        if (!done) {
            cout << -1 << endl;
            return 0;
        }
    }
    m++;
    vector<unordered_set<int>> swapped(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (b[i][j] > b[i + 1][j]) {
                swapped[j].insert(i);
            }
        }
    }

    vector<int> ans;
    vector<int> ok(n - 1);
    fill(used, used + m, false);
    while (ans.size() != m) {
        vector<int> new_col;
        for (int j = 0; j < m; j++) {
            if (used[j])
                continue;
            if (swapped[j].empty()) {
                new_col.push_back(j);
                used[j] = true;
            }
        }
        if (new_col.empty()) {
            cout << -1 << endl;
            return 0;
        }
        vector<int> new_ok;
        for (auto j : new_col) {
            for (int i = 0; i < n - 1; i++) {
                if (ok[i])
                    continue;
                if (b[i][j] != b[i + 1][j]) {
                    new_ok.push_back(i);
                    ok[i] = true;
                }
            }
            ans.push_back(j);
        }
        for (int j = 0; j < m; j++) {
            if (used[j])
                continue;
            for (auto i : new_ok) {
                if (swapped[j].count(i))
                    swapped[j].erase(i);
            }
        }
    }
    while (ans.back() != m - 1)
        ans.pop_back();
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a + 1 << " ";
    cout << endl;

    return 0;
}