#include <cstdio>
#include <cstring>
#define ll long long
#define fo(i, x, y) for(ll i = x; i <= y; i ++)
#define fd(i, x, y) for(ll i = x; i >= y; i --)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const ll w = 4, M = 10000, mo = 1e9 + 7;
const ll ni = 5e8 + 4;

char s[10005];
struct node {
    ll w, a[10005];
}n;
ll len, num[10005];
ll a[10005], p, k;
const int N = 3400;
ll f[2][N][2][2]; int o;

ll chu(node &a, ll b) {
    ll y = 0;
    fd(i, a.w, 1) {
        a.a[i] += y * M;
        y = a.a[i] % b; a.a[i] /= b;
    }
    while(a.w > 1 && a.a[a.w] == 0) a.w --;
    return y;
}

void Init() {
    scanf("%I64d %I64d", &p, &k);
    scanf("%s", s + 1); len = strlen(s + 1);
    n.w = 0; ll v = 0;
    fd(i, len, 1) {
        v = (v + 1) % 4;
        n.w += v == 1; num[i] = n.w;
    }
    fo(i, 1, len) n.a[num[i]] = n.a[num[i]] * 10 + s[i] - 48;
    while(!(n.w == 1 && n.a[1] == 0))
        a[++ a[0]] = chu(n, p);
}

ll s1(ll x, ll y) {
    if(x > y) return 0;
    x %= mo; y %= mo;
    ll z = (y - x + 1) % mo;
    return (2 * p - 1) % mo * z % mo - (x + y) * z % mo * ni % mo;
}

ll s2(ll x, ll y) {
    if(x > y) return 0;
    x %= mo; y %= mo;
    return (x + y + 2) % mo * (y - x + 1) % mo * ni % mo;
}

void End() {
    f[0][0][0][0] = 1;
    fo(i, 1, a[0]) {
		o = !o;
		memset(f[o], 0, sizeof f[o]);
        fo(j, 0, i) {
            fo(la, 0, 1) {
                if(a[i] >= la)
                    f[o][j][0][0] += f[!o][j][la][0] * s2(a[i] - la, a[i] - la) % mo,
                    f[o][j][0][1] += f[!o][j][la][1] * s2(a[i] - la, a[i] - la) % mo;
                f[o][j][0][0] += (f[!o][j][la][0] + f[!o][j][la][1]) % mo * s2(0, a[i] - la - 1) % mo;
                f[o][j][0][1] += (f[!o][j][la][0] + f[!o][j][la][1]) % mo * s2(a[i] - la + 1, p - 1 - la) % mo;
                f[o][j][0][0] %= mo; f[o][j][0][1] %= mo;
                if(j == 0) continue;

                f[o][j][1][0] += f[!o][j - 1][la][0] * s1(a[i] - la + p, a[i] - la + p) % mo;
                f[o][j][1][1] += f[!o][j - 1][la][1] * s1(a[i] - la + p, a[i] - la + p) % mo;
                f[o][j][1][0] += (f[!o][j - 1][la][0] + f[!o][j - 1][la][1]) % mo * s1(p - la, a[i] - la - 1 + p) % mo;
                f[o][j][1][1] += (f[!o][j - 1][la][0] + f[!o][j - 1][la][1]) % mo * s1(a[i] - la + 1 + p, 2 * p - 1) % mo;    
                f[o][j][1][0] %= mo; f[o][j][1][1] %= mo;           
            }
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    Init();
    if(k > a[0]) {
        printf("0\n");
        return 0;
    }
    End();
    ll ans = 0;
    fo(i, k, a[0]) ans += f[o][i][0][0];
    ans  = (ans % mo + mo) % mo;
    printf("%I64d\n", ans);
}