#include <cstdio>
#include <algorithm>
#include <utility>
static const int INF = 0x7fffffff;
static const int MAXN = 100003;

int n, p, t;
std::pair<int, int> ans[MAXN * 2];
std::pair<int, int> tmp[MAXN * 2];
#define pos  first
#define cnt  second

int main()
{
    scanf("%*d%d%d%d", &n, &p, &t); // I'm sorry, L > <

    int ans_ct = 1, tmp_ct;
    ans[0] = std::make_pair(-INF, 0);

    int ans_pr = 0;
    int l, r;
    do {
        scanf("%d%d", &l, &r);
        while (ans_pr < ans_ct && ans[ans_pr].pos + t < l) ++ans_pr;
        --ans_pr;

        tmp_ct = 1;
        tmp[0] = std::make_pair(r - (r - l) % p, ans[ans_pr].cnt + (r - l) / p);
        ++ans_pr;
        while (ans_pr < ans_ct && ans[ans_pr].pos + t <= r) {
            int x = ans[ans_pr].pos + t;
            tmp[tmp_ct++] = std::make_pair(r - (r - x) % p, ans[ans_pr].cnt + (r - x) / p);
            ++ans_pr;
        }

        std::sort(tmp, tmp + tmp_ct);
        for (int i = 0; i < tmp_ct; ++i) {
            if (ans[ans_ct - 1].cnt < tmp[i].cnt)
                ans[ans_ct++] = tmp[i];
        }
    } while (--n);

    printf("%d\n", ans[ans_ct - 1].cnt);
    return 0;
}