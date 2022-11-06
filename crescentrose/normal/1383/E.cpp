#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
const int N = 2e6;
char s[N];
int n;
int ans, ans1;
int cnt[N];
int d[N], nxt[N];
vector<int> w;
int f[N], ff[N];
int main() {
    scanf("%s", s);
    n = strlen(s);
    int tot= 0;
    bool first = 1;
    ans1 = 1;
    for (int i = 0; i < n; i ++)
        if (s[i] == '1') {
            cnt[i] = tot;
            tot = 0;
            if (first) {
                ans1 = mul(ans1, cnt[i] + 1);
                first = 0;
                cnt[i] = -1;
            }
            d[++d[0]] = i;
        } else {
            tot ++;
        }
    ans1 = mul(ans1, tot + 1);
    if (!d[0]) {
        printf("%d\n", n);
        return 0;
    }
    for (int i = d[0]; i >= 1; i --) {
        while (w.size() && cnt[d[w[w.size() - 1]]] <= cnt[d[i]]) w.pop_back();
        if (w.size())
            nxt[i] = w[w.size() - 1];
        w.push_back(i);
    }
    f[1] = 1;
    for (int i = 1; i < d[0]; i ++) {
        f[i + 1] = add(f[i + 1], mul(f[i], cnt[d[i + 1]] +1));
        ff[i + 1] = add(ff[i + 1], f[i]);
        if (nxt[i])
        {
            f[nxt[i]] = add(f[nxt[i]], mul(ff[i], cnt[d[nxt[i]]] - cnt[d[i]]));
            ff[nxt[i]] = add(ff[nxt[i]], ff[i]);
        }
        ans = add(ans, f[i]);
    }
    ans = add(ans, f[d[0]]);
    printf("%d\n", mul(ans, ans1));
    return 0;
}