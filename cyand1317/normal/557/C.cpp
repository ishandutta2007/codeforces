#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
static const int MAXN = 100003;
typedef std::pair<int, int> table;
#define length first
#define energy second

int main()
{
    int n;
    table t[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i].length);
    for (int i = 0; i < n; ++i) scanf("%d", &t[i].energy);
    std::sort(t, t + n);

    int future_sum = 0, now_sum = 0, past_sum = 0;
    for (int i = 0; i < n; ++i) future_sum += t[i].energy;
    int j, now_len, k, cur_ans, ans = 0x7fffffff;
    typedef std::multiset<int, std::greater<int> > past_type;
    past_type past;
    past_type::iterator it1;
    for (int i = 0; i < n;) {
        past_sum += now_sum;
        now_sum = t[i].energy;
        future_sum -= t[i].energy;
        j = i + 1;
        while (j < n && t[j].length == t[j - 1].length) {
            now_sum += t[j].energy;
            future_sum -= t[j].energy;
            ++j;
        }
        now_len = j - i;
        k = std::min(now_len - 1, (int)past.size());
        // Keep the largest k elements in @ref past.
        cur_ans = past_sum + future_sum;
        for (it1 = past.begin(); k--; ++it1) cur_ans -= *it1;
        if (ans > cur_ans) ans = cur_ans;
        // Jump to the next block with the same length
        for (; i < j; ++i) past.insert(t[i].energy);
    }

    printf("%d\n", ans);
    return 0;
}