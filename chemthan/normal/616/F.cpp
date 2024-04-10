#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int MAXN = 600010;
char T[MAXN];
int nlen;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN];
int Phi[MAXN], PLCP[MAXN];
int LCP[MAXN];
void countingsort(int k) {
    int sum = 0, maxi = max(300, nlen);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < nlen; i++) c[i + k < nlen ? RA[i + k] : 0]++;
    for (int i = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (int i = 0; i < nlen; i++) tempSA[c[SA[i] + k < nlen ? RA[SA[i] + k] : 0]++] = SA[i];
    for (int i = 0; i < nlen; i++) SA[i] = tempSA[i];
}
void constructSA() {
    int r;
    for (int i = 0; i < nlen; i++) RA[i] = T[i];
    for (int i = 0; i < nlen; i++) SA[i] = i;
    for (int k = 1; k < nlen; k <<= 1) {
        countingsort(k);
        countingsort(0);
        tempSA[SA[0]] = r = 0;
        for (int i = 1; i < nlen; i++) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (int i = 0; i < nlen; i++) RA[i] = tempRA[i];
        if (RA[SA[nlen - 1]] == nlen - 1) break;
    }
}
void computeLCP() {
    int L = 0;
    Phi[SA[0]] = -1;
    for (int i = 1; i < nlen; i++) Phi[SA[i]] = SA[i - 1];
    for (int i = 0; i < nlen; i++) {
        if (Phi[i] == -1) {PLCP[i] = 0; continue;}
        while (T[i + L] == T[Phi[i] + L] && T[i + L] != '$') L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (int i = 0; i < nlen; i++) LCP[i] = PLCP[SA[i]];
}

const int maxn = 600010;
int n;
char s[maxn];
int cost[maxn];
int pos[maxn];
int COST[maxn];
int maxlen[maxn];
int MAXLEN[maxn];
ll SUMCOST[maxn];
int l[maxn];
int r[maxn];

ll calc(int l, int r) {
    if (!l) return SUMCOST[r];
    return SUMCOST[r] - SUMCOST[l - 1];
}

void solve() {
    ms(pos, -1);
    scanf("%d", &n);
    FOR(i, 0, n) {
        scanf("%s", s);
        int d = strlen(s);
        FOR(j, 0, d) {
            pos[nlen] = i;
            maxlen[nlen] = d - j;
            T[nlen++] = s[j];
        }
        T[nlen++] = '$';
    }
    FOR(i, 0, n) scanf("%d", cost + i);
    constructSA(); computeLCP();
    FOR(i, 0, nlen) {
        if (~pos[i]) {
            COST[RA[i]] = cost[pos[i]];
            MAXLEN[RA[i]] = maxlen[i];
        }
    }
    FOR(i, 0, nlen) {
        if (!i) SUMCOST[i] = COST[i];
        else SUMCOST[i] = SUMCOST[i - 1] + COST[i];
    }
    FOR(i, 0, nlen) l[i] = r[i] = i;
    FOR(i, 1, nlen) {
        int cur = i;
        while (cur && LCP[i] <= LCP[cur - 1]) cur = l[cur - 1];
        l[i] = cur;
    }
    FORd(i, nlen - 1, 0) {
        int cur = i;
        while (cur < nlen - 1 && LCP[i] <= LCP[cur + 1]) cur = r[cur + 1];
        r[i] = cur;
    }
    ll ans = 0;
    FOR(i, 1, nlen) {
        ans = max(ans, LCP[i] * calc(l[i] - 1, r[i]));
        if (MAXLEN[i] > LCP[i] && (i == nlen - 1 || MAXLEN[i] > LCP[i + 1])) ans = max(ans, MAXLEN[i] * calc(i, i));
    }
    printf("%I64d", ans);
}

int main() {
//  ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}