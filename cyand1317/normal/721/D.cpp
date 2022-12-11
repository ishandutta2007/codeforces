#include <cstdio>
#include <cstdlib>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 200005;

int n, k, x;
int64 a[MAXN];
typedef std::pair<int64, int> record;
#define num  first
#define idx  second
typedef std::priority_queue<record,
    std::vector<record>, std::greater<record>
> container;

container q;

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    bool is_neg = false;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        if (a[i] < 0) is_neg ^= 1;
        q.push(record(std::abs(a[i]), i));
    }

    int special_idx = -1;
    if (!is_neg) {
        record r = q.top(); q.pop();
        if (r.num > (int64)k * x) {
            q.push(record(r.num - (int64)k * x, r.idx));
            k = 0;
        } else {
            int ct = r.num / x + (r.num % x == 0 ? 0 : 1);
            k -= ct;
            q.push(record(-(r.num - (int64)ct * x), r.idx));
            special_idx = r.idx;
        }
    }
    while (k > 0) {
        record r = q.top(); q.pop();
        q.push(record(r.num + x, r.idx));
        --k;
    }

    while (!q.empty()) {
        record r = q.top(); q.pop();
        a[r.idx] = r.num * (a[r.idx] >= 0 ? 1 : -1);
    }
    if (special_idx != -1) a[special_idx] *= -1;
    for (int i = 0; i < n; ++i)
        printf("%I64d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}