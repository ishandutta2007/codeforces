#include <cstdio>
#include <queue>
typedef long long int64;
static const int MAXN = 200003;

int n;
int a_i;
std::priority_queue<int64, std::vector<int64>, std::greater<int64>> q;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        q.push(a_i);
    }
    while (q.size() % 2 != 1) q.push(0);

    int64 ans = 0;
    while (q.size() > 1) {
        int64 x = q.top(); q.pop();
        x += q.top(); q.pop();
        x += q.top(); q.pop();
        ans += x;
        q.push(x);
    }

    printf("%I64d\n", ans);
    return 0;
}