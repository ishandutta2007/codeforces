#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

class SegmentTree {
private:
	int n;
	vi A, st, rv;
	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1) + 1;}
	void build(int p, int L, int R) {
		if (L == R) {st[p] = L; rv[L] = p;}
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int u = st[left(p)];
			int v = st[right(p)];
			st[p] = A[u] <= A[v] ? u : v;
		}
	}
	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (i <= L && j >= R) return st[p];
		int u = rmq(left(p), L, (L + R) / 2, i, j);
		int v = rmq(right(p), (L + R) / 2 + 1, R, i, j);
		if (u == -1) return v;
		if (v == -1) return u;
		return A[u] <= A[v] ? u : v;
	}
public:
	void init(int a[], int len) {
		n = len;
		FOR(i, 0, n) A.push_back(a[i]);
		st.assign(4 * n, 0);
		rv.assign(n, 0);
		build(1, 0, n - 1);
	}
	void init(const vi &_A) {
		A = _A;
		n = sz(_A);
		st.assign(4 * n, 0);
		rv.assign(n, 0);
		build(1, 0, n - 1);
	}
	void modify(int i, int k) {
		A[i] = k;
		int p = rv[i];
		while (p >>= 1) {
			int u = st[left(p)], v = st[right(p)];
			st[p] = A[u] <= A[v] ? u : v;
		}
	}
	int rmq(int a, int b){
		return rmq(1, 0, n - 1, a, b);
	}
};

int const maxn = 1000010;
int n, nq;
int nlen;
char T[maxn];
int len[maxn];
int x[maxn];
int w[maxn];
int rev[maxn];
int ans[maxn];
ll mp[maxn];
vector<pair<int, pair<pi, pi> > > q;
SegmentTree smt;

int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn];
int Phi[maxn], PLCP[maxn];
int LCP[maxn];
void countingsort(int k) {
	int sum = 0, maxi = max(300, nlen);
	ms(c, 0);
	FOR(i, 0, nlen) c[i + k < nlen ? RA[i + k] : 0]++;
	FOR(i, 0, maxi) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	FOR(i, 0, nlen) tempSA[c[SA[i] + k < nlen ? RA[SA[i] + k] : 0]++] = SA[i];
	FOR(i, 0, nlen) {SA[i] = tempSA[i]; rev[SA[i]] = i;}
}
void constructSA() {
	FOR(i, 0, nlen) RA[i] = T[i];
	FOR(i, 0, nlen) SA[i] = i;
	int r;
	for (int k = 1; k < nlen; k <<= 1) {
		countingsort(k);
		countingsort(0);
		tempSA[SA[0]] = r = 0;
		FOR(i, 1, nlen) tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		FOR(i, 0, nlen) RA[i] = tempRA[i];
		if (RA[SA[nlen - 1]] == nlen - 1) break;
	}
}
void computeLCP() {
	ms(LCP, 0);
	int L = 0;
	Phi[SA[0]] = -1;
	FOR(i, 1, nlen) Phi[SA[i]] = SA[i - 1];
	FOR(i, 0, nlen) {
		if (Phi[i] == -1) {PLCP[i] = 0; continue;}
		while (T[i + L] == T[Phi[i] + L] && T[i + L] != '$') L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	FOR(i, 0, nlen) LCP[i] = PLCP[SA[i]];
}

int fen[maxn];
void add(int p, int val) {
	for (p++; p < maxn; p += p & -p) fen[p] += val;
}
int get(int p)
{
	int res = 0;
	for (; p > 0; p -= p & -p) res += fen[p];
	return res;
}

void query(int k, int l, int r, int id) {
	int i = rev[x[k]];
	ll u, v;
	if (!mp[i]) {
		if (LCP[i] < len[k] && LCP[i + 1] < len[k]) u = v = i;
		else {
			int a, b;
			if (LCP[i] >= len[k]) {
				a = 0, b = i;
				while (a < b) {
					int mid = (a + b) >> 1;
					if (LCP[smt.rmq(mid, b)] < len[k]) a = mid + 1; else b = mid;
				}
				u = a - 1;
			}
			else u = i;
			if (LCP[i + 1] >= len[k]) {
				a = i + 1, b = nlen - 1;
				while (a < b) {
					int mid = (a + b + 1) >> 1;
					if (LCP[smt.rmq(a, mid)] >= len[k]) a = mid; else b = mid - 1;
				}
				v = a;
			}
			else v = i;
		}
		mp[i] = (u << 32) + v;
	}
	else {
		u = mp[i] >> 32;
		v = mp[i] % (1LL << 32);
	}
	q.push_back(make_pair(u - 1, make_pair(pi(l, r), pi(-1, id))));
	q.push_back(make_pair(v, make_pair(pi(l, r), pi(1, id))));
}

void solve() {
	ms(T, 0); ms(w, -1); ms(mp, 0); ms(fen, 0);
	scanf("%d%d", &n, &nq);
	nlen = 0;
	char s[maxn];
	FOR(i, 0, n) {
		x[i] = nlen;
		scanf("%s", s); len[i] = strlen(s);
		FOR(j, x[i], x[i] + len[i]) w[j] = i;
		strcpy(T + nlen, s); nlen += len[i];
		T[nlen++] = '$';
	}
	constructSA();
	computeLCP();
	smt.init(LCP, nlen);
	int l, r, k; FOR(i, 0, nq) {scanf("%d%d%d", &l, &r, &k); l--; r--; k--; query(k, l, r, i);}
	sort(q.begin(), q.end());
	ms(ans, 0);
	int po = 0;
	FOR(i, 0, sz(q)) {
		while (po < nlen && po <= q[i].first) {if (w[SA[po]] >= 0) add(w[SA[po]] + 1, 1); po++;}
		ans[q[i].second.second.second] += q[i].second.second.first * (get(q[i].second.first.second + 2) - get(q[i].second.first.first + 1));
	}
	FOR(i, 0, nq) printf("%d\n", ans[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}