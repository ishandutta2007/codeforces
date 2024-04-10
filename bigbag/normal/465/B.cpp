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

const int max_n = 1111, inf = 1111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int last = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (last == -1 || last + 1 == i) {
                ++ans;
            } else {
                ans += 2;
            }
            last = i;
        }
    }
    cout << ans << endl;
    return 0;
}