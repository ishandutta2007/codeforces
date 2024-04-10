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

const int max_n = 1, inf = 1111111111;
const int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int l, r, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        int x = i;
        while (x) {
            ans += a[x % 10];
            x /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}