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

const int max_n = 222222;

int n, sum, a[max_n], b[max_n];
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        sum += a[i];
        q.insert(b[i]);
    }
    for (int i = 0; i < n; ++i) {
        q.erase(q.find(b[i]));
        int mx = *q.rbegin();
        q.insert(b[i]);
        printf("%d ", mx * (sum - a[i]));
    }
    return 0;
}