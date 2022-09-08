#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m;
long long sum;
pair<int, int> a[max_n];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first - a.second > b.first - b.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
        sum += a[i].first;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i <= n; ++i) {
        if (sum <= m) {
            printf("%d\n", i);
            return 0;
        }
        sum += a[i].second - a[i].first;
    }
    printf("-1\n");
    return 0;
}