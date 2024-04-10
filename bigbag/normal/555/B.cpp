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

const int max_n = 222222, inf = 1111111111;

int n, m, ans[max_n];
long long l[max_n], r[max_n];
set<pair<long long, int> > q;
vector<pair<long long, pair<int, int> > > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &l[i], &r[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        long long mx = r[i + 1] - l[i];
        v.push_back(make_pair(mx, make_pair(2, i)));
    }
    for (int i = 0; i < m; ++i) {
        long long x;
        scanf("%I64d", &x);
        v.push_back(make_pair(x, make_pair(1, i)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        int num = v[i].second.second;
        if (v[i].second.first == 1) {
            q.insert(make_pair(v[i].first, num));
        } else {
            long long mn = l[num + 1] - r[num];
            if (q.size() == 0) {
                printf("No\n");
                return 0;
            }
            pair<long long, int> p = *q.rbegin();
            if (p.first >= mn) {
                p = *q.lower_bound(make_pair(mn, -1));
            } else {
                printf("No\n");
                return 0;
            }
            q.erase(p);
            ans[num] = p.second;
        }
    }
    printf("Yes\n");
    for (int i = 0; i + 1 < n; ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return 0;
}