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

int q;
map<pair<long long, long long>, long long> ans;

long long lca(long long u, long long v) {
    vector<long long> q;
    while (u) {
        q.push_back(u);
        u /= 2;
    }
    int poz = 0;
    while (v) {
        while (q[poz] > v) {
            ++poz;
        }
        if (q[poz] == v) {
            return v;
        }
        v /= 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    while (q--) {
        int tp;
        long long u, v;
        scanf("%d%I64d%I64d", &tp, &u, &v);
        long long lc = lca(u, v);
        if (tp == 1) {
            int cost;
            scanf("%d", &cost);
            while (u != lc) {
                ans[make_pair(u / 2, u)] += cost;
                u /= 2;
            }
            while (v != lc) {
                ans[make_pair(v / 2, v)] += cost;
                v /= 2;
            }
        } else {
            long long res = 0;
            while (u != lc) {
                res += ans[make_pair(u / 2, u)];
                u /= 2;
            }
            while (v != lc) {
                res += ans[make_pair(v / 2, v)];
                v /= 2;
            }
            printf("%I64d\n", res);
        }
    }
    return 0;
}