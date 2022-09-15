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
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 2010;
const int maxp = 510;
char s[maxn];
char p[maxp];
int slen, plen;
int nxt[maxn];
int f[maxn][maxn];

int cal(int pos, int del) {
	if (pos == slen) if (del == 0) return 0; else return INT_MIN;
	if (f[pos][del] != -1) return f[pos][del];
	int res = INT_MIN;
	if (nxt[pos] != -1 && del >= nxt[pos] - pos + 1 - plen) {
		int k = cal(nxt[pos] + 1, del - (nxt[pos] - pos + 1 - plen));
		if (k >= 0) res = k + 1;
	}
	res = max(res, cal(pos + 1, del));
	if (del) res = max(res, cal(pos + 1, del - 1));
	return f[pos][del] = res;
}

void solve() {
	ms(nxt, -1); ms(f, -1);
	scanf("%s%s", s, p);
	slen = strlen(s);
	plen = strlen(p);
	FOR(i, 0, slen) {
		int cur = i, idx = 0;
		while (cur < slen) {
			if (s[cur] == p[idx]) idx++;
			if (idx == plen) break;
			cur++;
		}
		if (cur < slen) nxt[i] = cur;
	}
	FOR(i, 0, slen + 1) printf("%d ", max(0, cal(0, i)));
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}