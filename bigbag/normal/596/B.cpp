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

const int max_n = 222222, inf = 1111111111;

int n, a[max_n];
long long ans;

int my_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i == 0) {
            ans += my_abs(a[i]);
        } else {
            ans += my_abs(a[i] - a[i - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}