#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define P pair<int, int>
using namespace std;
const int N = 50005, mo = 998244353, pri = 1e9 + 7, pri2 = 43313;
char str[N];
int n, bz[N], tmp;
ll c[N], ni[N], s[N];
ll ksm(ll x, ll y) {
    ll s = 1;
    for(; y; x = x * x % mo, y >>= 1)
        if(y & 1) s = s * x % mo;
    return s;
}
void Getsum() {
    fo(i, 1, n) s[i] = (s[i - 1] + c[i] * (str[i] - 'a') % mo) % mo;
}
int sum(int x, int y) {
    return ((s[y] - s[x - 1] + mo) * ni[x] % mo);
}
int Getq(int x, int y) {
    int ans = 0;
    for(int l = 1, r = tmp; l <= r;) {
        int m = l + r >> 1;
        if(sum(x - m + 1, x) == sum(y - m + 1, y))
            ans = m, l = m + 1; else r = m - 1;
    }
    return ans;
}
int Geth(int x, int y) {
    int ans = 0;
    for(int l = 1, r = n - y + 1; l <= r;) {
        int m = l + r >> 1;
        if(sum(x, x + m - 1) == sum(y, y + m - 1))
            ans = m, l = m + 1; else r = m - 1;
    }
    return ans;
}
int main() {
    scanf("%s", str + 1); n = strlen(str + 1);
    c[0] = ni[0] = 1;
    ni[1] = ksm(pri, mo - 2); c[1] = pri;
    fo(i, 2, n) ni[i] = ni[i - 1] * ni[1] % mo, c[i] = c[i - 1] * c[1] % mo;
    int n0 = n; Getsum();
    fo(l, 1, n) {
        int xg = 0; tmp = l;
        fo(i, 1, n / l) {
            int x = i * l, y = x + l;
            if(y > n) break;
            int q = Getq(x, y), h = Geth(x, y);
            if(q + h > l) {
                fo(j, x - q + 1, x - q + l) bz[j] = l;
                tmp = q;
                xg = 1;
            } else tmp = l;
        }
        if(xg) {
            int n1 = 0;
            fo(i, 1, n) if(bz[i] != l)
                str[++ n1] = str[i];
            n = n1;
            Getsum();
        }
    }
    fo(i, 1, n) putchar(str[i]);
}