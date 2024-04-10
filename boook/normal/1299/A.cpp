/*input
4
4 0 11 6
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 100000 + 10

int x[maxn], fr[maxn], ba[maxn], n;
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) fr[i] = fr[i - 1] | x[i];
    for (int i = n; i >= 1; -- i) ba[i] = ba[i + 1] | x[i];

    int big = -1, idx = 0;
    for (int i = 1; i <= n; ++ i){
        int v1 = fr[i - 1], v2 = ba[i + 1];
        int val = (((x[i] | v1) - v1) | v2) - v2;
        if (val > big) big = val, idx = i;
    }
    swap(x[idx], x[1]);
    for (int i = 1; i <= n; ++ i)
        cout << x[i] << " \n"[i == n];
    return 0;
}