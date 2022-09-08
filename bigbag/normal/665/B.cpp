#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int n, m, k, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    n *= m;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    while (n--) {
        int x, poz;
        cin >> x;
        for (int i = 0; i < k; ++i) {
            if (a[i] == x) {
                poz = i;
                break;
            }
        }
        ans += poz + 1;
        for (int i = poz; i; --i) {
            a[i] = a[i - 1];
        }
        a[0] = x;
    }
    cout << ans << endl;
    return 0;
}