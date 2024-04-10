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

const int max_n = 333333, inf = 2011111111;

int n, k, ans, pos;
pair<int, pair<int, int> > p[max_n];
vector<pair<int, int> > v;
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second.first);
        p[i].second.second = i;
    }
    sort(p, p + n);
    pos = n - 1;
    for (int i = 0; i < n; ++i) {
        q.insert(p[i].second.first);
        if (q.size() > k) {
            int mn = *q.begin();
            q.erase(q.find(mn));
        }
        if (q.size() == k) {
            int mn = *q.begin();
            if (ans < mn - p[i].first + 1) {
                ans = mn - p[i].first + 1;
                pos = i;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i <= pos; ++i) {
        v.push_back(make_pair(p[i].second.first, p[i].second.second));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < k; ++i) {
        printf("%d ", v[i].second + 1);
    }
    printf("\n");
    return 0;
}