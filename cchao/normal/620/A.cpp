#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for(int i = (a); i <= int(b); ++i)
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BR putchar('\n')
#define MS0(ar) memset(ar, 0, sizeof(ar))
#define MS1(ar) memset(ar, -1, sizeof(ar))
#define F first
#define S second
#define MP make_pair
#define MT make_tuple

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef complex<double> CD;

void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(ULL &x) { scanf("%llu", &x); }
void R(double &x) { scanf("%lf", &x); }
void R(LD &x) { scanf("%Lf", &x); }

template<typename T>
void R(T &t) { cin >> t; }
template<typename T>
void R(vector<T> &ar) { for(auto &it : ar) R(it); }

template<typename T, typename... Args>
void R(T &t, Args&... args) {
	R(t);
	R(args...);
}

void W(const int &x) { printf("%d", x); }
void W(const LL &x) { printf("%lld", x); }
void W(const ULL &x) { printf("%llu", x); }
void W(const double &x) { printf("%lf", x); }
void W(const LD &x) { printf("%Lf", x); }

template<typename T>
void W(const T &t) { cout << t; }
template<typename T>
void W(const vector<T> &ar) {
	for(size_t i = 0; i < ar.size(); ++i) {
		W(ar[i]);
		putchar(" \n"[i + 1u == ar.size()]);
	}
}
template<typename T, typename... Args>
void W(const T &t, const Args&... args) {
	W(t);
	W(args...);
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

int main() {
	int x1, y1, x2, y2;
	R(x1, y1, x2, y2);
	W(max(abs(x1 - x2), abs(y1 - y2)), "\n");
	return 0;
}