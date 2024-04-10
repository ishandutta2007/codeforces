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

const int max_n = 111, inf = 1011111111;

int n, cnt, a[max_n];
queue<int> q;
set<pair<int, int> > all;
vector<pair<int, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i) {
            all.insert(make_pair(a[i], i));
        }
    }
    q.push(0);
    while (!q.empty()) {
        ++cnt;
        int v = q.front();
        q.pop();
        while (all.size() && a[v]--) {
            pair<int, int> mx = *all.rbegin();
            all.erase(mx);
            q.push(mx.second);
            ans.push_back(make_pair(v, mx.second));
        }
    }
    if (cnt != n) {
        printf("-1\n");
    } else {
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        }
    }
    return 0;
}