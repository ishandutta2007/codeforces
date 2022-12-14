#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n, k;
long long b, c;

long long t[200020];

vector<long long> ss[5];
int st[5], en[5];

long long price(long long s, long long x) {
    long long m5 = (x - s) / 5;
    long long rp = (x - s) % 5;
    long long dis;
    if (5 * c <= b) {
        dis = (x - s) * c;
    } else {
        dis = m5 * b + rp * c;
    }
    // printf("DIST %lld %lld :: %lld\n", s, x, dis);
    return dis;
}

long long pmod(long long x, long long m) {
    long long r = x % m;
    if (r < 0) {
        r += m;
    }
    return r;
}

int main() {
    scanf("%d %d %lld %lld", &n, &k, &b, &c);
    set<long long> xs;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &t[i]);
        xs.insert(t[i]);
    }
    sort(t, t + n);
    for (int i = 0; i < n; ++i) {
        int rt = t[i] % 5;
        if (rt < 0) {
            rt += 5;
        }
        ss[rt].push_back(t[i]);
    }

    long long ans = (1LL << 62);
    for (int rm = 0; rm < 5; ++rm) {
        for (int i = 0; i < 5; ++i) {
            st[i] = ss[i].size() - 1;
            en[i] = st[i];
        }
        long long x = *xs.rbegin();
        while (pmod(x, 5) != rm) {
            ++x;
        }
        int put = 0;
        long long cur = 0;
        while (put < k) {
            int bi;
            for (int i = 0; i < 5; ++i) {
                if (st[i] >= 0) {
                    bi = i;
                    break;
                }
            }
            if (bi == -1) {
                break;
            }
            for (int i = 0; i < 5; ++i) {
                if (st[i] < 0) {
                    continue;
                }
                if (price(ss[i][st[i]], x) < price(ss[bi][st[bi]], x)) {
                    bi = i;
                }
            }
            ++put;
            cur += price(ss[bi][st[bi]], x);
            --st[bi];
        }
        if (put == k) {
            ans = min(ans, cur);
        }
        long long px = x;
        for (set<long long>::reverse_iterator it = xs.rbegin(); it != xs.rend(); ++it) {
            if (*it == *xs.rbegin()) {
                continue;
            }
            long long x = (*it);
            while (pmod(x, 5) != rm) {
                ++x;
            }
            // printf("Operating with x=%lld px=%lld\n", x, px);
            for (int i = 0; i < 5; ++i) {
                // if (en[i] < ss[i].size()) {
                    // printf("ST %d EN %d KVO %lld\n", st[i], en[i], ss[i][en[i]]);
                // }
                while (en[i] >= 0 && en[i] > st[i] && ss[i][en[i]] > x) {
                    cur -= price(ss[i][en[i]], px);
                    --put;
                    --en[i];
                }
            }
            long long cx = px - x;
            long long d5 = cx / 5;
            cur -= d5 * min(b, 5LL * c) * put;
            // printf("CUR %lld before x=%lld and put=%d\n", cur, x, put);
            while (put < k) {
                int bi = -1;
                for (int i = 0; i < 5; ++i) {
                    while (st[i] >= 0 && ss[i][st[i]] > x) {
                        --st[i];
                        en[i] = st[i];
                    }
                    if (st[i] >= 0) {
                        bi = i;
                    }
                }
                if (bi == -1) {
                    break;
                }
                for (int i = 0; i < 5; ++i) {
                    if (st[i] < 0) {
                        continue;
                    }
                    if (price(ss[i][st[i]], x) < price(ss[bi][st[bi]], x)) {
                        bi = i;
                    }
                }
                ++put;
                cur += price(ss[bi][st[bi]], x);
                --st[bi];
            }
            if (put == k) {
                ans = min(ans, cur);
            }
            px = x;
        }
    }
    printf("%lld\n", ans);
    return 0;
}