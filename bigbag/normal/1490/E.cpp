/**
 *  created: 16/02/2021, 16:53:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
pair<int, int> a[max_n];

bool check(int id) {
    long long sum = a[id].first;
    for (int i = 0; i < n; ++i) {
        if (i == id) {
            continue;
        }
        if (sum < a[i].first) {
            return false;
        }
        sum += a[i].first;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        int l = -1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        vector<int> ans;
        for (int i = r; i < n; ++i) {
            ans.push_back(a[i].second);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int x : ans) {
            printf("%d ", x + 1);
        }
        puts("");
    }
    return 0;
}