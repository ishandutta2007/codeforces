#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;
typedef double r32;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int NX = 6005;
int n, m, q, p, a, b, x[NX]; pair<r32, r32> s[NX << 1]; r32 ans[NX];
int main() {
	read(n); read(q); read(a); read(b);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	for (int i = 1; i <= n; i++) {
		if(i == 1) {
			s[++m] = mp(1, 2 * (1 - x[i]));
			s[++m] = mp(q, 2 * (q - x[i]));
		} else {
			for (int j = m; j > p; j--)
				s[j + 2] = s[j];
			m += 2;
			s[p + 1] = mp(ans[i - 1], 0);
			s[p + 2] = mp(ans[i - 1], 0);
			
			for (int j = 1; j <= p + 1; j++)
				s[j].X += a;
			for (int j = p + 2; j <= m; j++)
				s[j].X += b;
			for (int j = 1; j <= m; j++)
				s[j].Y += 2 * (s[j].X - x[i]);
		}
		if(s[1].Y >= 0) {
			p = 0; ans[i] = s[1].X;
		} else {
			for (p = 1; p <= m; p++)
				if(s[p].Y <= 0 && s[p + 1].Y > 0) break;
			ans[i] = s[p].X - s[p].Y * (s[p + 1].X - s[p].X) / (s[p + 1].Y - s[p].Y);
		}
		//for (int j = 1; j <= m; j++)
		//	printf("%lf, %lf ", s[j].X, s[j].Y); puts("");
	}
	cmin(ans[n], (r32) q);
	for (int i = n - 1; i; i--)
		ans[i] = max(ans[i + 1] - b, min(ans[i], ans[i + 1] - a));
	r32 cost = 0;
	for (int i = 1; i <= n; i++) {
		printf("%.6lf ", ans[i]);
		cost += (ans[i] - x[i]) * (ans[i] - x[i]);
	}
	printf("\n%.6lf", cost);
	return 0;
}