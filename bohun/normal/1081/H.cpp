#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;		

const int N = 2e5 + 100;
const int LOG = 17;
const int base = 31;
const int mod[2] = {(int)1e9 + 7, (int) 1e9 + 9};

struct Pal {
	char s[N];
	int nxt[N][26], fail[N], last[N], anc[N][LOG + 1], len[N], pos[N], cnt;
	
	Pal() {
		last[0] = 1;
		cnt = 1;
		fail[0] = fail[1] = 1;
		len[1] = -1;
	}
	
	void add(int n) {
		int c = s[n] - 'a';
		int v = last[n - 1];
		while (s[n - len[v] - 1] != s[n]) v = fail[v];
		if (!nxt[v][c]) {
			int now = ++cnt, k = fail[v];
			pos[now] = n;
			len[now] = len[v] + 2;
			while (s[n - len[k] - 1] != s[n]) k = fail[k];
			fail[now] = nxt[k][c], nxt[v][c] = now;
		}
		last[n] = nxt[v][c];
	}
	
	void build() {
		int n = strlen(s + 1);
		rep(i, 1, n)
			add(i);
		
		rep(i, 0, cnt) anc[i][0] = fail[i];
		
		rep(i, 0, cnt)
			rep(j, 1, LOG)
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
	}
	
	bool czypal(int l, int r) {
		int L = r - l + 1;
		int v = last[r];
		per(i, 0, LOG)
			if (len[anc[v][i]] >= L)
				v = anc[v][i];
		return len[v] == L;
	}
	
	int qw(int l, int r) {
		int L = r - l + 1;
		int v = last[r];
		if (len[v] <= L) return len[v];
		per(i, 0, LOG)
			if (len[anc[v][i]] > L)
				v = anc[v][i];
		return len[anc[v][0]];
	}
		
} A, B, AR, BR;


char a[N], b[N];

int P[N][2];
int HA[N][2];
int HB[N][2];

int AA(int l, int r, int j) {
	return (HA[r][j] - 1LL * HA[l - 1][j] * P[r - l + 1][j] % mod[j] + mod[j]) % mod[j];
}

int BB(int l, int r, int j) {
	return (HB[r][j] - 1LL * HB[l - 1][j] * P[r - l + 1][j] % mod[j] + mod[j]) % mod[j];
}

ll Ahasz(int l, int r) {
	return 1LL * AA(l, r, 0) * mod[0] + AA(l, r, 1);
}

ll Bhasz(int l, int r) {
	return 1LL * BB(l, r, 0) * mod[0] + BB(l, r, 1);
}

ll Atwo(int l1, int r1, int l2, int r2) {
	int x = (AA(l2, r2, 0) + 1LL * AA(l1, r1, 0) * P[r2 - l2 + 1][0] % mod[0]) % mod[0];
	int y = (AA(l2, r2, 1) + 1LL * AA(l1, r1, 1) * P[r2 - l2 + 1][1] % mod[1]) % mod[1];
	return 1LL * x * mod[0] + y;
}	
	
ll Btwo(int l1, int r1, int l2, int r2) {
	int x = (BB(l2, r2, 0) + 1LL * BB(l1, r1, 0) * P[r2 - l2 + 1][0] % mod[0]) % mod[0];
	int y = (BB(l2, r2, 1) + 1LL * BB(l1, r1, 1) * P[r2 - l2 + 1][1] % mod[1]) % mod[1];
	return 1LL * x * mod[0] + y;
}	
	

unordered_map <ll, int> PA, PB, GA, GB;

int main() {
	scanf ("%s%s", a + 1, b + 1);
	int n = strlen(a + 1), m = strlen(b + 1);
	
	P[0][0] = P[0][1] = 1;
	rep(i, 1, N - 1)
		rep(j, 0, 1)
			P[i][j] = 1LL * P[i - 1][j] * base % mod[j];
	
	rep(i, 1, n)
		rep(j, 0, 1)
			HA[i][j] = (1LL * HA[i - 1][j] * base + a[i]) % mod[j];
			
	rep(i, 1, m)
		rep(j, 0, 1)
			HB[i][j] = (1LL * HB[i - 1][j] * base + b[i]) % mod[j];
			
	rep(i, 1, n) 
		A.s[i] = AR.s[n - i + 1] = a[i];
	rep(i, 1, m)
		B.s[i] = BR.s[m - i + 1] = b[i];
	
	A.build();
	B.build();
	AR.build();
	BR.build();
	
	ll answer = 1LL * (A.cnt - 1) * (B.cnt - 1);
	
	rep(i, 2, A.cnt) {
		int p = A.fail[i];
		PA[Ahasz(A.pos[i] - A.len[i] + 1, A.pos[i])]++;
		if (!p) continue;
		if (2 * A.len[p] >= A.len[i])
			GA[Ahasz(A.pos[i] - (A.len[i] - A.len[p]) + 1, A.pos[i])]++;
	}
	
	rep(i, 2, B.cnt) {
		int p = B.fail[i];
		PB[Bhasz(B.pos[i] - B.len[i] + 1, B.pos[i])]++;
		if (!p) continue;
		if (2 * A.len[p] >= B.len[i])
			GB[Bhasz(B.pos[i] - B.len[i] + 1, B.pos[i] - B.len[p])]++;
	}
	
	rep(i, 2, A.cnt) {
		int p = A.fail[i];
		if (!p) continue;
		int l = A.pos[i] - (A.len[i] - A.len[p]) + 1, r = A.pos[i];
		
		if (GB.count(Ahasz(l, r)))
			answer -= GB[Ahasz(l, r)];
		
		int dlugosc = A.qw(l, r);
		if (dlugosc == r - l + 1 || dlugosc <= 0) continue;
		
		int mid = r - dlugosc + 1;
		if (A.czypal(l, mid - 1) == true) {
			//printf ("(%d %d), (%d %d)\n", l, mid - 1, mid, r);
			ll H1 = Ahasz(l, mid - 1);
			ll H2 = Atwo(l, r, l, mid - 1);
			if (PB.count(H1) && PB.count(H2)) answer--;
			continue;
		}
		dlugosc = AR.qw(n - r + 1, n - l + 1);
		if (dlugosc <= 0) continue;
		
		mid = l + dlugosc - 1;
		if (A.czypal(mid + 1, r) == true) {
			ll H1 = Ahasz(l, mid);
			ll H2 = Atwo(l, r, l, mid);
			if (PB.count(H1) && PB.count(H2)) answer--;
		}
	}
	
	rep(i, 2, B.cnt) {
		int p = B.fail[i];
		if (!p) continue;
		int l = B.pos[i] - B.len[i] + 1, r = B.pos[i] - B.len[p];
		
		if (GA.count(Bhasz(l, r)))
			answer -= GA[Bhasz(l, r)];
		
		int dlugosc = B.qw(l, r);
		if (dlugosc == r - l + 1 || dlugosc <= 0) continue;
		
		int mid = r - dlugosc + 1;
			
		if (B.czypal(l, mid - 1) == true) {
			ll H1 = Bhasz(mid, r);
			ll H2 = Btwo(mid, r, l, r);
			if (PA.count(H1) && PA.count(H2)) answer--;
			continue;
		}
		
		dlugosc = BR.qw(m - r + 1, m - l + 1);
		if (dlugosc <= 0) continue;
		
		mid = l + dlugosc - 1;
		
		if (B.czypal(mid + 1, r) == true) {
			ll H1 = Bhasz(mid + 1, r);
			ll H2 = Btwo(mid + 1, r, l, r);
			if (PA.count(H1) && PA.count(H2)) answer--;
		}
	}
	
	rep(i, 2, A.cnt) {
		int p = A.fail[i];
		if (!p) continue;
		if (2 * A.len[p] < A.len[i])
			GA[Ahasz(A.pos[i] - (A.len[i] - A.len[p]) + 1, A.pos[i])]++;
	}
	
	rep(i, 2, B.cnt) {
		int p = B.fail[i];
		if (!p) continue;
		if (2 * B.len[p] < B.len[i])
			GB[Bhasz(B.pos[i] - B.len[i] + 1, B.pos[i] - B.len[p])]++;
	}
	
	for (auto it : GA)
		answer += 1LL * it.se * GB[it.fi];
			
	printf ("%lld\n", answer);
	return 0;
}