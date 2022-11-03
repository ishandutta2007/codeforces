#include <cstdio>
#include <cstring>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

const int max_n = 1e3 + 100;
const int max_m = 1e3 + 100;

int c1, c2, c3, c4, n, m;
int a[max_n], b[max_m], aa[max_n], ab[max_m];

int main() {
    cin >> c1 >> c2 >> c3 >> c4 >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    aa[0] = min(c1 * a[0], c2);
    for (int i = 1; i < n; ++i)
        aa[i] = aa[i - 1] + min(c1 * a[i], c2);
    ab[0] = min(c1 * b[0], c2);
    for (int i = 1; i < m; ++i)
        ab[i] = ab[i - 1] + min(c1 * b[i], c2);
    int ans = c4;
    ans = min(ans, c3 + c3);
    ans = min(ans, c3 + aa[n - 1]);
    ans = min(ans, c3 + ab[m - 1]);
    ans = min(ans, aa[n - 1] + ab[m - 1]);
    cout << ans << endl;
    return 0;
}