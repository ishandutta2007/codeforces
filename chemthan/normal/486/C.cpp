#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 100010;
int n, p;
char s[maxn];
int d[maxn];

void solve() {
    ms(d, 0);
    scanf("%d%d%s", &n, &p, s);
    int cnt = 0;
    FOR(i, 0, n) {
        d[i] = min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
        cnt += d[i];
//        cout<<i<<" "<<d[i]<<"\n";
    }
    cnt >>= 1;
    if (2 * p >= n) p = n - p + 1; p--;
//    cout<<p<<"\n";
    int fir = -1, las;
    FOR(i, 0, n >> 1) {
        if (d[i]) {
            if (fir == -1) fir = i;
            las = i;
        }
    }
//    cout<<cnt<<"\n";
//    cout<<las<<" "<<fir<<"\n";
    if (fir == -1) {printf("0"); return;}
    if (p >= las) {printf("%d", cnt + p - fir); return;}
    printf("%d", cnt + min(abs(las - p), abs(p - fir)) + las - fir);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}