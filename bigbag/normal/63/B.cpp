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

const int max_n = 111, inf = 111111111;

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    while (a[0] != k) {
        ++ans;
        for (int i = 0; i < n; ++i) {
            int poz = i;
            while (poz + 1 < n && a[poz] == a[poz + 1] && a[poz] != k) {
                ++poz;
            }
            ++a[poz];
            i = poz;
        }
        sort(a, a + n);
    }
    cout << ans << endl;
    return 0;
}