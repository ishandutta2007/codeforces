#include <cstdio>
#include <queue>
#include <utility>
typedef long long int64;
static const int MAXN = 1e5 + 3;
static const int INF = 0x7fffffff;

int n, m;
int c[MAXN], w[MAXN];
std::priority_queue< std::pair<int, int> > q;
bool required_change[MAXN] = { false };

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);

    int64 dissatisfaction = 0;
    for (int i = 0; i < n; ++i) if (c[i] % 100 != 0) {
        q.push(std::make_pair(-(100 - c[i] % 100) * w[i], i));
        m -= (c[i] % 100);
        if (m < 0) {
            std::pair<int, int> r = q.top(); q.pop();
            dissatisfaction += (-r.first);
            required_change[r.second] = true;
            m += 100;
        }
    }

    printf("%I64d\n", dissatisfaction);
    for (int i = 0; i < n; ++i) {
        if (required_change[i]) printf("%d 0\n", c[i] / 100 + 1);
        else printf("%d %d\n", c[i] / 100, c[i] % 100);
    }

    return 0;
}