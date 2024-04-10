#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int N = 3e5 + 10;
map<pair<int, int>, int> w;
pair<int, int> a[N];
struct node{
    int son[2];
    int sum;
}f[N * 20];
int root[N];
int n, tot;
void ins(int s, int s1, int l, int r, int v) {
    f[s1] = f[s];
    f[s1].sum ++;
    if (l == r) return;
    if ((l + r) / 2 >= v) {
        f[s1].son[0] = ++ tot;
        ins(f[s].son[0], f[s1].son[0], l, (l + r )/ 2, v);
    } else {
        f[s1].son[1] = ++ tot;
        ins(f[s].son[1], f[s1].son[1], (l + r )/ 2 + 1, r, v);
    }
}
int get(int s, int s1, int l, int r, int ll) {
    if (!(f[s1].sum - f[s].sum)) return 0;
    if (r <= ll) return f[s1].sum - f[s].sum;
    if (l > ll) return 0;
    return get(f[s].son[0], f[s1].son[0], l, (l + r) / 2, ll)  + get(f[s].son[1], f[s1].son[1], (l + r) / 2 + 1, r, ll);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        root[i] = root[i  - 1];
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j ++)
            scanf("%d %d", &a[j].first, &a[j].second);
        for (int j = 0; j < m; j ++) {
            pair<int, int> u = make_pair(a[(j + 1) % m].first - a[j].first, a[(j + 1) % m].second - a[j].second);
            if (!u.first && !u.second) continue;
            int v = __gcd(abs(u.first), abs(u.second));
            u.first /= v, u.second /= v;
            int tmp = ++tot;
            ins(root[i], tmp, 0, n, w[u]);
            w[u] = i;
            root[i] = tmp;
        }
    }
    int m;
    scanf("%d", &m);
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", get(root[l - 1], root[r], 0, n, l - 1));
    }
    return 0;
}