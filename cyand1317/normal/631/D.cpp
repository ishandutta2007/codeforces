#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
typedef unsigned long long hash_t;
static const int MAXN = 200004;
static const int HASH_BASE = 1e9 + 7;

int n, m;
typedef std::pair<char, int64> seg;
typedef std::vector<seg> str;
str s, t;

hash_t s_hash[MAXN], t_hash;
hash_t HBASE_POW[MAXN];

inline void read_str(int n, str &s)
{
    int num; char chr, last = '\0';
    for (int i = 0; i < n; ++i) {
        scanf("%d-%c", &num, &chr);
        if (chr == last) s.rbegin()->second += num;
        else s.push_back(seg(chr, num));
        last = chr;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    read_str(n, s);
    read_str(m, t);

    s_hash[0] = (s[0].first - 'a' + s[0].second * 26);
    for (int i = 1; i < s.size(); ++i)
        s_hash[i] = s_hash[i - 1] * HASH_BASE + (s[i].first - 'a' + s[i].second * 26);
    HBASE_POW[0] = 1;
    for (int i = 1; i < MAXN; ++i) HBASE_POW[i] = HBASE_POW[i - 1] * HASH_BASE;

    int64 ans = 0;
    if (t.size() == 1u) {
        for (int i = 0; i < s.size(); ++i)
            if (s[i].first == t[0].first) ans += std::max<int64>(0, s[i].second - t[0].second + 1);
    } else if (t.size() == 2u) {
        seg first_margin = t.front(), last_margin = t.back();
        for (int p = 1; p < s.size(); ++p)
            if (s[p - 1].first == first_margin.first && s[p - 1].second >= first_margin.second &&
                s[p].first == last_margin.first && s[p].second >= last_margin.second)
            {
                ++ans;
            }
    } else {
        seg first_margin = t.front(), last_margin = t.back();
        t.erase(t.begin()); t.pop_back();
        t_hash = 0;
        for (int i = 0; i < t.size(); ++i)
            t_hash = t_hash * HASH_BASE + (t[i].first - 'a' + t[i].second * 26);
        for (int p = 1; p + t.size() < s.size(); ++p) if (s_hash[p + t.size() - 1] - s_hash[p - 1] * HBASE_POW[t.size()] == t_hash) {
            if (p - 1 >= 0 && p + t.size() < s.size() &&
                s[p - 1].first == first_margin.first && s[p - 1].second >= first_margin.second &&
                s[p + t.size()].first == last_margin.first && s[p + t.size()].second >= last_margin.second)
            {
                ++ans;
            }
        }
    }

    printf("%I64d\n", ans);
    return 0;
}