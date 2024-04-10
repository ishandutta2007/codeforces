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

const int max_n = 4444, inf = 1111111111;

int n, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int poz = 0;
    while (poz < n && a[poz] == 0) {
        ++poz;
    }
    for (int i = poz; i < n; ++i) {
        if (a[i] == 1) {
            ++ans;
            continue;
        }
        if (a[i - 1] == 0) {
            continue;
        }
        if (a[i + 1] == 0) {
            continue;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}