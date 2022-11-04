#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 25005, maxq = 100005;
int n, q;
int a[maxn], le[maxn];
pair<int, int> pp[maxn], ps[maxn], sp[maxn], ss[maxn];

int main() {
    scanf("%d%d", &n, &q);
    cont(i, n) scanf("%d", a + i);
    cont(i, n) {
        pp[i] = mak(0, 0);
        ps[i] = mak(n + 1, 0);
        sp[i] = mak(0, 0);
        ss[i] = mak(n + 1, 0);
        le[i] = i;
    }
    int ans = 0;
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        int now = r + 1;
        while (le[now - 1] > l) --now;
        for (; now <= r; ++now) {
            while (le[now] > l) {
                --le[now];
                int pre = le[now];
                if (a[pre] < a[now] && a[now] < ss[pre].first) {
                    if (ss[pre].second) {
                        int nxt = ss[pre].second;
                        pp[nxt].second = 0;
                        --ans;
                    }
                    ss[pre] = mak(a[now], now);
                    if (pp[now].second) {
                        int nxt = pp[now].second;
                        ss[nxt].second = 0;
                        --ans;
                    }
                    pp[now] = mak(a[pre], pre);
                    ++ans;
                }
                if (a[pre] > a[now] && a[now] > sp[pre].first) {
                    if (sp[pre].second) {
                        int nxt = sp[pre].second;
                        ps[nxt].second = 0;
                        --ans;
                    }
                    sp[pre] = mak(a[now], now);
                    if (ps[now].second) {
                        int nxt = ps[now].second;
                        sp[nxt].second = 0;
                        --ans;
                    }
                    ps[now] = mak(a[pre], pre);
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}