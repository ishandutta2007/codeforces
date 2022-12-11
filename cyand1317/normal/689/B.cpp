#include <cstdio>
#include <queue>
static const int MAXN = 1000007;

int n;
int a[MAXN];
int m[MAXN] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }

    std::queue<int> q;
    m[0] = 1; q.push(0);
    while (!q.empty()) {
        int r = q.front(); q.pop();
        //if (m[r] != 0) continue;
        if (r < n - 1 && m[r + 1] == 0) {
            m[r + 1] = m[r] + 1;
            q.push(r + 1);
        }
        if (r > 0 && m[r - 1] == 0) {
            m[r - 1] = m[r] + 1;
            q.push(r - 1);
        }
        if (m[a[r]] == 0) {
            m[a[r]] = m[r] + 1;
            q.push(a[r]);
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d%c", m[i] - 1, i == n - 1 ? '\n' : ' ');
    return 0;
}