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
long long sum[max_n];
map<long long, int> all;
set<long long> ans;
set<pair<int, int> > q;

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

void add(int l, int r) {
    if (l <= r) {
        q.insert(make_pair(l, r));
        int cnt = ++all[get_sum(l, r)];
        if (cnt == 1) {
            ans.insert(get_sum(l, r));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
    }
    for (int i = 1; i < n; ++i) {
        sum[i] += sum[i - 1];
    }
    add(0, n - 1);
    for (int i = 0; i < n; ++i) {
        int poz;
        scanf("%d", &poz);
        --poz;
        auto it = q.upper_bound(make_pair(poz + 1, poz + 1));
        --it;
        pair<int, int> p = *it;
        int l = p.first, r = p.second;
        int cnt = --all[get_sum(l, r)];
        if (cnt == 0) {
            ans.erase(get_sum(l, r));
        }
        q.erase(make_pair(l, r));
        add(l, poz - 1);
        add(poz + 1, r);
        if (ans.size() == 0) {
            printf("0\n");
        } else {
            printf("%I64d\n", *ans.rbegin());
        }
    }
    return 0;
}