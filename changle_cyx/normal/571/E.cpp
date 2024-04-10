#include <bits/stdc++.h>

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

inline void invalid() {
	puts("-1"); 
	exit(0); 
}

namespace ModuloCalculator {
	const int mod = 1e9 + 7; 
	inline int qpow(s64 x, s64 y) {
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1) res = 1LL * res * x % mod; 
		return res; 
	}
}
using namespace ModuloCalculator; 

const int MaxN = 1e5 + 5; 
const int MaxM = 1e5 + 5; 

struct node {
	s64 a, b; 
}f[MaxN], g[MaxN]; 

int ans; 
int nP, pri[MaxM]; 
int n, a[MaxM], b[MaxM]; 

template <class T>
inline T gcd(T n, T m) {
	return m ? gcd(m, n % m) : n; 
}

template <class T>
inline T getAbs(const T &x) {
	return x < 0 ? -x : x; 
}

template <class T>
inline void simplify(T &a, T &b, T &c) {
	T g = gcd(a, gcd(getAbs(b), getAbs(c))); 
	a /= g, b /= g, c /= g; 
}

template <class T>
inline T exgcd(const T &a, const T &b, T &x, T &y) {
	if (!b) {
		return x = 1, y = 0, a; 
	}
	T res = exgcd(b, a % b, y, x); 
	return y -= a / b * x, res; 
}

inline void getPri(int n) {
	int x = n; 
	for (int i = 2; i * i <= n; ++i)
		if (x % i == 0) {
			pri[++nP] = i; 
			while (x % i == 0) x /= i; 
		}
	if (x > 1) pri[++nP] = x; 
}

void solve(int va, int vb) {
	for (int i = 1; i <= nP; ++i) {
		g[i].a = g[i].b = 0; 
		while (va % pri[i] == 0) ++g[i].a, va /= pri[i]; 
		while (vb % pri[i] == 0) ++g[i].b, vb /= pri[i]; 
	}

	// std::cerr << "-----------\n"; 

	for (int tim = 1; tim <= 2; ++tim) {
		for (int i = 1; i <= nP; ++i) {
			if (!f[i].a && !g[i].a) {
				if (f[i].b != g[i].b) {
					invalid(); 
				}
			} else if (!f[i].a || !g[i].a) {
				if (!f[i].a) {
					// assert(g[i].a >= 0); 
					if (f[i].b < g[i].b || (f[i].b - g[i].b) % g[i].a) {
						invalid(); 
					}
					
					s64 cur = (f[i].b - g[i].b) / g[i].a; 
					for (int j = 1; j <= nP; ++j) {
						g[j].b += g[j].a * cur, g[j].a = 0; 
					}
				} else {
					// assert(f[i].a >= 0); 
					if (g[i].b < f[i].b || (g[i].b - f[i].b) % f[i].a) {
						invalid(); 
					}
					
					s64 cur = (g[i].b - f[i].b) / f[i].a; 
					for (int j = 1; j <= nP; ++j) {
						f[j].b += f[j].a * cur, f[j].a = 0; 
					}
				}
			}
		}
	}

	bool flg = false; 
	s64 X = -1, Y = -1; 
	s64 A = 0, B = 0, C = 0; 

	for (int i = 1; i <= nP; ++i) {
		s64 fa = f[i].a, fb = f[i].b; 
		s64 ga = g[i].a, gb = g[i].b; 
		if (!fa || !ga) continue; 

		// std::cout << fa << ' ' << fb <<'\n'; 

		s64 curA = fa, curB = -ga, curC = gb - fb; 
		if (!flg) {
			A = curA, B = curB, C = curC; 
			flg = true; 
		} else if (X == -1) {
			s64 g = gcd(curA, A);
			s64 d1 = A / g, d2 = curA / g; 
			curA *= d1, curB *= d1, curC *= d1;
			A *= d2, B *= d2, C *= d2; 

			if (curB == B) {
				if (curC != C) {
					invalid(); 
				}

				simplify(A, B, C); 
				continue; 
			} else {
				s64 dC = curC - C, dB = curB - B; 
				if (dC % dB || dC / dB < 0) {
					invalid(); 
				}
				Y = dC / dB; 

				simplify(A, B, C); 
				if ((C - B * Y) % A || (C - B * Y) / A < 0) {
					invalid(); 
				}
				X = (C - B * Y) / A; 
			}
		} else {
			if (curA * X + curB * Y != curC) { 
				invalid(); 
			}
		}
	}

	// std::cout << flg << ' ' << X << ' ' << Y << ':' << A << ' ' << B << ' ' << C << '\n'; 

	if (!flg) return; 

	if (X == -1) {
		__int128 x, y, d = exgcd((__int128)A, -(__int128)B, x, y); 
		// std::cout << ">>>>>" << A << ' ' << B << ' ' << C << ' ' << ':' << d << ':' << x << ' ' << y << '\n'; 

		if (C % d) {
			invalid(); 
		}

		x *= C / d, y *= -C / d; 
		__int128 modx = -B / d;
		__int128 mody = A / d; 
		__int128 tx = 0, ty = 0;

		if (x < 0) 
			tx = -((-x + modx - 1) / modx);
		else
			tx = x / modx;
		
		if (y < 0)
			ty = -((-y + mody - 1) / mody);
		else
			ty = y / mody;
		
		x -= modx * std::min(tx, ty);
		y -= mody * std::min(tx, ty);

		for (int i = 1; i <= nP; ++i) {
			f[i].b += f[i].a * x; 
			f[i].a *= modx; 
		}
	} else {
		for (int i = 1; i <= nP; ++i) {
			f[i].b += f[i].a * X; 
			f[i].a = 0; 
		}
	}
}

int main() {
#ifdef orzczk
	freopen("seq.in", "r", stdin); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(b[i]), read(a[i]); 
		getPri(a[i]), getPri(b[i]); 
	}
	
	std::sort(pri + 1, pri + nP + 1); 
	nP = std::unique(pri + 1, pri + nP + 1) - pri - 1; 

	for (int i = 1; i <= nP; ++i) {
		int x = a[1], y = b[1]; 
		while (x % pri[i] == 0) ++f[i].a, x /= pri[i]; 
		while (y % pri[i] == 0) ++f[i].b, y /= pri[i]; 
	}
	for (int i = 2; i <= n; ++i) {
		solve(a[i], b[i]); 
	}

	int res = 1; 
	for (int i = 1; i <= nP; ++i) {
		res = 1LL * res * qpow(pri[i], f[i].b) % mod; 
	}

	std::cout << res << '\n'; 

	return 0; 
}