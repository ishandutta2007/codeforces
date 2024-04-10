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

int a, b, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; i * 2 <= b && i <= a; ++i) {
        int xa = a - i;
        int xb = b - i * 2;
        ans = max(ans, i + min(xa / 2, xb));
    }
    cout << ans << endl;
    return 0;
}