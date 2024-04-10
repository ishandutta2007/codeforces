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

int n, m;
queue<pair<int, int> > q;
pair<int, pair<int, int> > p[max_n];
pair<int, int> ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second.first);
        p[i].second.first *= -1;
        p[i].second.second = i;
    }
    sort(p, p + m);
    int cnt = 1;
    for (int i = 0; i < m; ++i) {
        if (p[i].second.first == 0) {
            if (q.empty()) {
                printf("-1\n");
                return 0;
            }
            ans[p[i].second.second] = q.front();
            q.pop();
        } else {
            ++cnt;
            if (cnt == 2) {
                ans[p[i].second.second] = make_pair(1, 2);
            } else {
                for (int j = 2; j < cnt; ++j) {
                    q.push(make_pair(j, cnt));
                    if (q.size() >= m + 5) {
                        break;
                    }
                }
                ans[p[i].second.second] = make_pair(1, cnt);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}