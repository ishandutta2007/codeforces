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

const int max_n = 202222, inf = 1011111111;

int n, t;
pair<pair<int, int>, int> a[max_n];
vector<int> ans, num[2];
vector<pair<int, int>> v[2];

int get(int k) {
    ans.clear();
    v[0].clear();
    v[1].clear();
    num[0].clear();
    num[1].clear();
    for (int i = 0; i < n; ++i) {
        if (a[i].first.second < k) {
            v[0].push_back(a[i].first);
            num[0].push_back(a[i].second);
        } else {
            v[1].push_back(a[i].first);
            num[1].push_back(a[i].second);
        }
    }
    int tot = 0, cnt = 0;
    for (int i = 0; i < v[1].size() && cnt < k && tot + v[1][i].first <= t; ++i) {
        tot += v[1][i].first;
        ++cnt;
        ans.push_back(num[1][i]);
    }
    if (cnt < k) {
        return -1;
    }
    return k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first.second, &a[i].first.first);
        a[i].second = i;
    }
    sort(a, a + n);
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (get(mid) == mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    get(l);
    printf("%d\n", l);
    printf("%d\n", l);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return 0;
}