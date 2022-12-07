#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int P = 1e9 + 7, N = 205;

#define add(a, b) (a + b >= P ? a + b - P : a + b)
#define sub(a, b) (a - b < 0 ? a - b + P : a - b)

int exp(int a, int n) {
	int res = 1;
	for (; n; n >>= 1, a = (LL) a * a % P) 
		if(n & 1) res = (LL) res * a % P;
	return res;
}
struct Num {
	int a, b;
	Num(int a = 0, int b = 0) : a(a), b(b) {
		
	}
	Num operator + (Num r) {
		return Num(add(a, r.a), add(b, r.b));
	}
	Num operator - (Num r) {
		return Num(sub(a, r.a), sub(b, r.b));
	}
	
	Num operator * (Num r) {
		int ca = ((LL) a * r.a + (LL) b * r.b * 5) % P;
		int cb = ((LL) a * r.b + (LL) b * r.a) % P;
		return Num(ca, cb);
	} 
	Num conj() {
		return Num(a, P - b);
	}
	Num operator ^ (LL n) {
		Num res(1, 0), t = *this;
		for (; n; n >>= 1) {
			if(n & 1)
				res = res * t;
			t = t * t;
		}
		return res;
	}
	Num operator / (Num r) {
		Num t = r.conj();
		Num x = *this;
		
		//printf("??? %d %d\n", x.a, x.b);
		x = x * t; r = r * t;
		x = x * exp(r.a, P - 2);
		//printf("deb %d %d\n", x.a, x.b);
		return x;
	}
};

Num S, p, q;
Num fib(LL n) {
	Num res = (p ^ n) - (q ^ n);
	return res / S;
}

Num sum(Num x, LL n) {
	if(x.a == 1 && x.b == 0)
		return n % P;
	return x * (Num(1) - (x ^ n)) / (Num(1) - x);
}

Num c[N][N], s[N][N];
// sum C(fi, i)

Num f(LL n, int k) {
	Num res = 0;
	//puts("!!");
	for (int i = 0; i <= k; i++) {
		Num inc = sum((p ^ i) * (q ^ (k - i)), n) * c[k][i];
		//printf("i = %d %d %d --\n", i, (p ^ i).a, (p ^ i).b);
		//printf("%d %d\n", ((p ^ i) * (q ^ (k - i))).a, ((p ^ i) * (q ^ (k - i))).b);
		(k - i & 1) ? 
			res = res - inc:
			res = res + inc;
	}	
	return res * ((Num(1) / S) ^ k);
}

Num F[N];
Num solve(int k, LL n) {
	for (int i = 0; i <= k; i++) {
		F[i] = f(n, i);
	}
	Num res = 0;
	for (int i = 1; i <= k; i++) {
		Num inc = s[k][i] * F[i];
		(k - i & 1) ? 
			res = res - inc:
			res = res + inc;
	}
	return res;
}

void przy() {
	c[0][0] = 1;
	for (int i = 1; i < N; i++) {
		c[i][0] = 1;
		for (int j = 1; j < N; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	s[1][1] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 1; j <= i; j++) 
			s[i][j] = s[i - 1][j - 1] + s[i - 1][j] * (i - 1);
}

int main() {
	int n; LL l, r; 
	S = Num(0, 1);
	p = (S + 1) / 2; q = (Num(1) - S) / 2;
	przy();
	cin >> n >> l >> r;
	Num ans = solve(n, r + 2) - solve(n, l + 1);
	for (int i = 1; i <= n; i++)
		ans = ans / i;
	printf("%d\n", ans.a);
	return 0;
}