#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

const int max_n = 1e5 + 100;

int n, m;
int ans[max_n];
pair<int, int> l[max_n];
int a[max_n];
int b[max_n];

int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> l[i].first;
        --l[i].first;
        l[i].second = i;
    }
    sort(l, l + m);
    int last = n - 1;
    int cnt = 0;
    for (int i = m - 1; i >= 0; --i) {
        while (last >= l[i].first) {
            if (b[a[last]] == 0)
                ++cnt;
            ++b[a[last]];
            --last;
        }
        ans[l[i].second] = cnt;
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << endl;
    return 0;
}