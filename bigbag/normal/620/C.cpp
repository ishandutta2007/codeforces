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

const int max_n = 333333, inf = 1111111111;

int n, l, a[max_n];
set<int> q;
vector<pair<int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (q.count(a[i])) {
            v.push_back(make_pair(l, i));
            l = i + 1;
            q.clear();
        } else {
            q.insert(a[i]);
        }
    }
    if (l == 0) {
        printf("-1\n");
        return 0;
    }
    if (l != n) {
        v.back().second = n - 1;
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i) {
        printf("%d %d\n", v[i].first + 1, v[i].second + 1);
    }
    return 0;
}