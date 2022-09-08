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

const int max_n = 101111, max_x = 2255555, sz = 500, inf = 1111111111;

int n, m, k, a[max_n], b[max_n];
long long ans[max_n];
vector<int> poz[max_x];
vector<pair<int, pair<int, int> > > v;

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
    p1.first /= sz;
    p2.first /= sz;
    return p1 < p2;
}

int get(int l, int r, int x) {
    vector<int>::iterator it1 = lower_bound(poz[x].begin(), poz[x].end(), l);
    vector<int>::iterator it2 = upper_bound(poz[x].begin(), poz[x].end(), r);
    --it2;
    return it2 - it1 + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_x; ++i) {
        poz[i].push_back(-1);
    }
    scanf("%d%d%d", &n, &m, &k);
    poz[0].push_back(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i] ^ b[i - 1];
        poz[b[i]].push_back(i);
    }
    for (int i = 0; i < max_x; ++i) {
        poz[i].push_back(inf);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        v.push_back(make_pair(l, make_pair(r, i)));
    }
    sort(v.begin(), v.end(), cmp);
    int ll = inf, rr;
    long long res = 0, Q = 0;
    for (int i = 0; i < v.size(); ++i) {
        int l = v[i].first, r = v[i].second.first;
        if (l / sz != ll / sz || l > rr) {
            res = 0;
            for (int j = l; j <= r; ++j) {
                res += get(l - 1, j - 1, b[j] ^ k);
            }
            ll = l;
            rr = r;
        } else {
            if (l < ll) {
                for (int j = l; j < ll; ++j) {
                    res += get(j, rr, b[j - 1] ^ k);
                }
            } else if (l > ll) {
                for (int j = ll; j < l; ++j) {
                    res -= get(j, rr, b[j - 1] ^ k);
                }
            }
            for (int j = rr + 1; j <= r; ++j) {
                res += get(l - 1, j - 1, b[j] ^ k);
            }
            ll = l;
            rr = r;
        }
        ans[v[i].second.second] = res;
    }
    for (int i = 0; i < m; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}