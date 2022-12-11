#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

#define F(a, b, c) for (int a = b; a <= c; a++)
#define FW(a, b, c) for (int a = b; a >= c; a--)
template<class T>void RD(T& a) {cin >> a; }
template<class T>void RD(T& a, T& b) {cin >> a >> b; }
template<class T>void RD(T& a, T& b, T& c) {cin >> a >> b >> c; }
template<class T>void RD(T& a, T& b, T& c, T& d) {cin >> a >> b >> c >> d; }
template<class T>void WT(T a) {cout << a; }
template<class T>void WT(T a, T b) {cout << a << " " << b; }
template<class T>void WT(T a, T b, T c) {cout << a << " " << b << " " << c; }
template<class T>void WT(T a, T b, T c, T d) {cout << a << " " << b << " " << c << " " << d; } 
#define MP make_pair
#define STR string
#define itr ::iterator
#define opr operator
#define EX exit(0)
#define PB push_back
#define V(x) vector<x>
#define S(x) set<x>
#define M(x, y) map<x, y>
#define PQ(x) priority_queue<x>
#define PQ_(x) priority_queue<x, vector<x>, greater<x> >
#define LN putchar('\n')
#define GR(x) greater<x>
#define I int
#define LL long long
#define UI unsigned int
#define C char
#define ULL unsigned long long
#define be begin()
#define ed end()
#define ST(a, from, to) sort(a + from, a + to)
#define ST(a, x) sort(a + from, a + to, x)
template<class T>
inline T FP(T base, T exp, T mod) {
	T res = 1; base %= mod;
	for(; exp; exp >>= 1, base = base * base % mod) if (exp & 1) res = res * base % mod;
	return res;
}
template<class T>
inline T Eg(T a, T b, T &c, T &d) {
if (b == 0) c = 1, d = 0; else Eg(b, a % b, d, c), d -= a / b * c;
}
template<class T>
inline T inv(T x, T mod) {
	T ans, tmp;
	Eg(x, mod, ans, tmp);
	return (ans + mod) % mod;
}

int main() {
	I x;
    RD(x);
    while (x % 10 == 0) x /= 10;
    I c[10], cnt = 0;
    while (x) c[++cnt] = x % 10, x /= 10;
    for (int i = 1; i <= cnt; i++)
    	if (c[i] != c[cnt - i + 1]) {
    		puts("NO"); return 0;
		}
	puts("YES");
	return 0;
}