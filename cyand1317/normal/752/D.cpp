#include <cstdio>
#include <queue>
#include <map>
typedef long long int64;
static const int MAXN = 100009;

int n, k;
char *_pool, *s[MAXN];
int64 hash[MAXN], rhash[MAXN];
int a[MAXN];
std::map<int64, int64> rev;
std::map< int64, std::priority_queue<int> > m;

inline int64 hash_str(const char *s, int len, int inc) {
    int64 ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = (ans * 99997 + *(s + inc * i) - 23) % (int64)(1e12 + 7);
    }
    return (int64)ans;
}

int main()
{
    scanf("%d%d", &n, &k);
    _pool = new char[n * (k + 2)];

    for (int i = 0; i < n; ++i) {
        getchar();
        s[i] = _pool + i * (k + 2);
        for (int j = 0; j < k; ++j) s[i][j] = getchar();
        scanf("%d", &a[i]);
        hash[i] = hash_str(s[i], k, +1);
        rhash[i] = hash_str(s[i] + k - 1, k, -1);
        rev[hash[i]] = rhash[i];
        m[hash[i]].push(a[i]);
    }

    int ans = 0;
    for (std::map< int64, std::priority_queue<int> >::iterator i = m.begin(); i != m.end(); ++i) {
        if (rev[i->first] == i->first) continue;
        int64 r = rev[i->first];
        while (!i->second.empty()) {
            int cur = i->second.top(); i->second.pop();
            if (m[r].empty()) break;
            int other = m[r].top(); m[r].pop();
            if (cur + other > 0) ans += (cur + other); else break;
        }
    }
    int self_palin_max = 0;
    for (std::map< int64, std::priority_queue<int> >::iterator i = m.begin(); i != m.end(); ++i) {
        if (rev[i->first] != i->first) continue;
        while (!i->second.empty()) {
            int cur = i->second.top(); i->second.pop();
            if (i->second.empty()) {
                if (self_palin_max < cur) self_palin_max = cur;
                break;
            }
            int next = i->second.top(); i->second.pop();
            if (next >= 0) ans += (cur + next);
            else if (cur <= 0) break;
            else {
                if (next + cur >= 0) {
                    ans += (cur + next);
                    if (self_palin_max < -next) self_palin_max = -next;
                } else {
                    if (self_palin_max < cur) self_palin_max = cur;
                }
            }
        }
    }

    ans += self_palin_max;
    printf("%d\n", ans);
    return 0;
}