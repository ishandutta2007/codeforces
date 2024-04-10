#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

int n, m;
vector<int> a;
void getFail(char *P, int *f) {
    f[0] = f[1] = 0;
    for(int i = 1; i < m; ++i) {
        int j = f[i];
        while(j && P[i] != P[j]) j = f[j];
        f[i+1] = P[i] == P[j] ? j + 1 : 0;
    }
}

void finds(char *T, char *P, int *f) {
    getFail(P, f);
    for(int i = 0, j = 0; i < n; ++i) {
        while(j && P[j] != T[i]) j = f[j];
        if(P[j] == T[i]) ++j;
        if(j == m) {
            j = f[j];
            // printf("find %d\n", i);
            a.push_back(i - m + 1);
        }
    }
}

char T[100010], P[100010];
int f[100010], ed[100010];
const int mod = 1000000007;

int dp[100010], s[100010];
int go(int x) {
    if(x >= n) return 0;
    int &ret = dp[x];
    if(ret >= 0) return ret;
    ret = 0;

}

int main() {
    scanf("%s%s", T, P);
    n = strlen(T), m = strlen(P);
    finds(T, P, f);
    int j = 0;
    // for(auto v: a) printf("%d ", v); puts("");
    rep(i, n) {
        while(j < a.size() && a[j] < i) ++j;
        if(j == a.size()) ed[i] = -1;
        else ed[i] = a[j] + m - 1;
    }

    dp[n] = s[n] = 1;
    for(int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i+1];
        if(ed[i] >= 0) dp[i] = (dp[i] + s[ed[i] + 1]) % mod;
        s[i] = (dp[i] + s[i+1]) % mod;
    }

    int ans = dp[0] - 1;
    if(ans < 0) ans += mod;
    pi(ans);
    return 0;
}