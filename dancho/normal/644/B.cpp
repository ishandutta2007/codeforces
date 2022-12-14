#include <cstdio>
#include <queue>
#include <cstring>

int n, b;
std::queue<int> q;

long long t[1 << 20], d[1 << 20];
long long ans[1 << 20];

int main() {
    memset(ans, -1, sizeof(ans));
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &t[i], &d[i]);
    }
    long long ct = 0;
    int i = 0;
    while (i < n) {
        while (i < n && t[i] < ct) {
            if (q.size() < b) {
                q.push(i);
            }
            ++i;
        }
        if (q.size()) {
            int j = q.front();
            ct += d[j];
            ans[j] = ct;
            q.pop();
        } else {
            if (i < n) {
                ct = t[i] + d[i];
                ans[i] = ct;
                ++i;
            }
        }
    }
    while (q.size()) {
        int j = q.front();
        ct += d[j];
        ans[j] = ct;
        q.pop();
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld%c", ans[i], " \n"[i + 1 == n]);
    }
    return 0;
}