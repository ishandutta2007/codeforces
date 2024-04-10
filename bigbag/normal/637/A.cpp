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

const int max_n = 1111111, inf = 1111111111;

int n, a[max_n], last[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
        last[x] = i;
    }
    pair<int, pair<int, int> > ans = make_pair(-1, make_pair(-1, -1));
    for (int i = 0; i < max_n; ++i) {
        ans = max(ans, make_pair(a[i], make_pair(-last[i], i)));
    }
    printf("%d\n", ans.second.second);
    return 0;
}