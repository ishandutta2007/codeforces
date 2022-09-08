#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int n, b[max_n];
pair<int, int> a[max_n];
vector<int> ans1, ans2, ansd;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    vector<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (a[i].first == b[i]) {
            continue;
        }
        if (a[i].first < b[i]) {
            q.push_back({b[i] - a[i].first, a[i].second});
        } else {
            int tot = a[i].first - b[i];
            while (q.size() && tot) {
                int d = min(tot, q.back().first);
                ans1.push_back(q.back().second);
                ans2.push_back(a[i].second);
                ansd.push_back(d);
                q.back().first -= d;
                if (q.back().first == 0) {
                    q.pop_back();
                }
                tot -= d;
            }
            if (tot) {
                puts("NO");
                return 0;
            }
        }
    }
    if (q.size()) {
        puts("NO");
        return 0;
    }
    puts("YES");
    printf("%d\n", ans1.size());
    for (int i = 0; i < ans1.size(); ++i) {
        printf("%d %d %d\n", ans1[i] + 1, ans2[i] + 1, ansd[i]);
    }
    return 0;
}