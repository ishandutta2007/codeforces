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

int a, ta, b, tb, h, m, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d:%d", &a, &ta, &b, &tb, &h, &m);
    m += h * 60;
    for (int i = 300; i < 24 * 60; i += b) {
        if (i < m + ta && m < i + tb) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}