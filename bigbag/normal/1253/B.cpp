#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
vector<int> ans;
set<int> q, q2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) {
            if (q.count(a[i]) || q2.count(a[i])) {
                puts("-1");
                return 0;
            }
            q.insert(a[i]);
            q2.insert(a[i]);
        } else {
            a[i] *= -1;
            if (!q.count(a[i])) {
                puts("-1");
                return 0;
            }
            q.erase(a[i]);
        }
        ++cnt;
        if (q.empty()) {
            ans.push_back(cnt);
            q2.clear();
            cnt = 0;
        }
    }
    if (!q.empty()) {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}