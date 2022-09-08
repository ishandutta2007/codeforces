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

const int max_n = 555555, inf = 1111111111;

int n, k, t, d;
multiset<long long> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &t, &d);
        if (q.size() < k) {
            printf("%d\n", t + d);
            q.insert(t + d);
        } else {
            long long t1 = *q.begin();
            q.erase(q.find(t1));
            if (t1 < t) t1 = t;
            printf("%I64d\n", t1 + d);
            q.insert(t1 + d);
        }
    }
    return 0;
}