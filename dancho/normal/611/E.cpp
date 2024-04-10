#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n;

int m[3];

multiset<int, greater<int> > t;
int ta, tb;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &m[i]);
    }
    sort(m, m + 3);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        t.insert(k);
    }

    int a = m[0], b = m[1], c = m[2];
    int step = 0;
    while (t.size()) {
        int k = *t.begin();
        if (k <= c) {
            break;
        }
        if (a + b >= k) {
            t.erase(t.begin());
            auto it = t.lower_bound(c);
            if (it != t.end()) {
                t.erase(it);
            }
            ++step;
            continue;
        }
        if (a + c >= k) {
            t.erase(t.begin());
            auto it = t.lower_bound(b);
            if (it != t.end()) {
                t.erase(it);
            }
            ++step;
            continue;
        }
        if (b + c >= k) {
            t.erase(t.begin());
            auto it = t.lower_bound(a);
            if (it != t.end()) {
                t.erase(it);
            }
            ++step;
            continue;
        }
        if (a + b + c >= k) {
            t.erase(t.begin());
            ++step;
            continue;
        }
        printf("-1\n");
        return 0;
    }

    // <= c.

    int na, nb, nab;
    na = nb = nab = 0;
    int nc = 0;
    for (auto i : t) {
        if (i <= a) {
            ++na;
        } else if (i <= b) {
            ++nb;
        } else if (i <= a + b) {
            ++nab;
        } else {
            ++nc;
        }
    }

    // kolko ot nab sa s a + b i kolko s c?
    int ans = n;
    for (int i = 0; i <= nab; ++i) {
        // i s a + b;
        int pa, pb, pab, pc;
        pa = na;
        pb = nb;
        pc = 0;
        pab = 0;
        int ms = max(nab + nc - i, i);
        // ms sas c
        if (i < ms) {
            // rem sas a + b
            int rem = ms - i;
            if (nb < rem) {
                pb = 0;
                pa -= (rem - nb);
            } else {
                pb -= rem;
            }
            pa -= rem;
        } else {
            int rem = i - ms;
            // rem sas c
            if (nb < rem) {
                pb = 0;
                pa -= (rem - nb);
            } else {
                pb -= rem;
            }
            // pa -= rem;
        }
        if (pa < 0) {
            pa = 0;
        }
        if (pa == 0 && pb == 0) {
            ans = min(ans, ms + step);
        } else {
            int mbs = (pb + 1) / 2;
            int rem = mbs * 2 - pb;
            pa -= rem;
            pa -= mbs;
            if (pa <= 0) {
                ans = min(ans, ms + mbs + step);
            } else {
                ans = min(ans, ms + mbs + step + (pa + 2) / 3);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}