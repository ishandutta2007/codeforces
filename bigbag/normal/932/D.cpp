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

const int max_n = 400444, max_lev = 20;
const long long inf = 1000111222333444;

int q, n, p[max_lev][max_n], mx[max_lev][max_n];
int p2[max_lev][max_n];
long long sum[max_lev][max_n];
long long last, w[max_n];

void update(int v, int parent) {
    p[0][v] = parent;
    mx[0][v] = w[parent];
    for (int i = 1; i < max_lev; ++i) {
        p[i][v] = p[i - 1][p[i - 1][v]];
        mx[i][v] = max(mx[i - 1][v], mx[i - 1][p[i - 1][v]]);
    }
}

void add_edge(int v, int parent) {
    p2[0][v] = parent;
    sum[0][v] = w[parent];
    for (int i = 1; i < max_lev; ++i) {
        p2[i][v] = p2[i - 1][p2[i - 1][v]];
        sum[i][v] = sum[i - 1][v] + sum[i - 1][p2[i - 1][v]];
    }
}

int longest(int start, long long tot) {
    if (tot < w[start]) {
        return 0;
    }
    tot -= w[start];
    int res = 1;
    for (int i = max_lev - 1; i >= 0; --i) {
        if (sum[i][start] <= tot) {
            //cout << "$" << start << "   " << i << " -> " << p2[i][start] << endl;
            tot -= sum[i][start];
            start = p2[i][start];
            res += (1 << i);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &q);
    w[0] = inf;
    n = 1;
    update(n, 0);
    add_edge(n, 0);
    while (q--) {
        int tp;
        long long P, Q;
        scanf("%d%I64d%I64d", &tp, &P, &Q);
        if (tp == 1) {
            int parent = P ^ last;
            int weight = Q ^ last;
            ++n;
            w[n] = weight;
            update(n, parent);
            int first = n;
            for (int i = max_lev - 1; i >= 0; --i) {
                if (mx[i][first] < w[n]) {
                    first = p[i][first];
                }
            }
            first = p[0][first];
            //cout << n << " " << first << endl;
            add_edge(n, first);
        } else {
            int start = P ^ last;
            long long tot = Q ^ last;
            //cout << "longest " << start << " " << tot << endl;
            last = longest(start, tot);
            printf("%d\n", last);
        }
    }
    return 0;
}