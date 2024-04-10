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

int n, ans, num[max_n], sz[max_n], s[max_n];
pair<int, int> p;
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p.first, &p.second);
        ans += p.first;
        sz[i] = p.first;
        s[i] = p.second;
        p.second = i;
        q.insert(p);
    }
    printf("%d\n", ans / 2);
    for (int i = 0; i < n; ++i) {
        p = *q.begin();
        q.erase(p);
        if (p.first == 1) {
            int v = p.second;
            int v2 = s[v];
            printf("%d %d\n", v, v2);
            q.erase(make_pair(sz[v2], v2));
            --sz[v2];
            s[v2] ^= v;
            q.insert(make_pair(sz[v2], v2));
        }
    }
    return 0;
}