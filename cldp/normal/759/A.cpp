#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;
const int INF = 1000000009;
const double PI = acos(-1.0);

int p[MAXN], d[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> p[i];
    for (int i = 1; i <= N; ++i) cin >> d[i];
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (p[i] == 0) continue;
        int j = i;
        ++cnt;
        while (p[j] != i) {
            int k = j;
            j = p[j];
            p[k] = 0;
        }
        p[j] = 0;
    }
    if (cnt == 1) cnt = 0;
    int ans = 0;
    for (int i = 1; i <= N; ++i) ans += d[i];
    if (ans % 2 == 0) cout << cnt + 1 << endl; else cout << cnt << endl;
    return 0;
}