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

const int max_n = 1111111, inf = 1111111111;

int n, k;
vector<pair<int, int> > p, ans, ans2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        p.push_back(make_pair(l, 1));
        p.push_back(make_pair(r, 2));
    }
    sort(p.begin(), p.end());
    int cnt = 0, l;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i].second == 1) {
            ++cnt;
            if (cnt == k) {
                l = p[i].first;
            }
        } else {
            --cnt;
            if (cnt == k - 1) {
                ans.push_back(make_pair(l, p[i].first));
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        int poz = i;
        while (i + 1 < n && ans[i].second == ans[i + 1].first) {
            ++i;
        }
        ans2.push_back(make_pair(ans[poz].first, ans[i].second));
    }
    printf("%d\n", ans2.size());
    for (int i = 0; i < ans2.size(); ++i) {
        printf("%d %d\n", ans2[i].first, ans2[i].second);
    }
    return 0;
}