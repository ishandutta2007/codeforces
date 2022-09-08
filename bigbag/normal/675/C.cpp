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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n];
map<long long, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ++q[sum];
    }
    int ans = 0;
    for (map<long long, int>::iterator it = q.begin(); it != q.end(); ++it) {
        ans = max(ans, (*it).second);
    }
    printf("%d\n", n - ans);
    return 0;
}