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

const int max_n = 200222, inf = 1011111111;

int n, ans, a[max_n];
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    ans = 1;
    q.insert(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (q.count(a[i])) {
            q.erase(q.find(a[i]));
            q.insert(i);
        } else {
            q.insert(i);
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}