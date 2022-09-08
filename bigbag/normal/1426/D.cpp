#include <bits/stdc++.h>

using namespace std;

const int max_n = 200022, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long sum = 0;
    set<long long> q;
    q.insert(sum);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (q.count(sum)) {
            ++ans;
            q.clear();
            q.insert(0);
            sum = a[i];
        }
        q.insert(sum);
    }
    printf("%d\n", ans);
    return 0;
}