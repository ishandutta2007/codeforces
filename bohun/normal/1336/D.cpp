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

pair<int,int> ask(int x) {
	printf ("+ %d\n", x);
	fflush(stdout);
	int a, b;
	scanf ("%d%d", &a, &b);
	return {a,b};
}

int qw(int x) {
	int q = 0;
	while (q * (q - 1) / 2 < x) q++;
	return q;
}

int n, A, B, res[111];

int main() {
	scanf ("%d", &n);
	scanf ("%d%d", &A, &B);
	auto q1 = ask(1);
	auto q2 = ask(2);
	auto q3 = ask(3);
	auto q4 = ask(1);
	
	// 1.
	res[1] = qw(q4.fi - q3.fi) - 1;
	if (res[1] < 0) res[1] = 0;
	// 3.
	if (q3.fi - q2.fi > 0) res[3] = qw(q3.fi - q2.fi);
	else res[3] = (q2.se - q1.se == 0 ? 0 : 1);
	// 2.
	int ilo = q4.se - q3.se;
	res[2] = ilo / (res[3] + 1) - 1;
	
	int magic = q3.se - q2.se;
	int last1 = q4.fi;
	int last2 = q4.se;
	
	rep(i, 4, n - 1) {
		auto q = ask(i);
		magic -= (res[i - 2] + 1) * (res[i - 3] + 1);
		if (q.fi != last1) res[i] = qw(q.fi - last1);
		else res[i] = (magic == 0 ? 0 : 1);
		magic = q.se - last2;
		last1 = q.fi;
		last2 = q.se;
	}
	magic -= (res[n - 2] + 1) * (res[n - 3] + 1);
	res[n] = magic / (res[n - 2] + 1);
	
	printf ("!");
	rep(i, 1, n) printf (" %d", res[i]);
	printf ("\n");
	fflush(stdout);
	
	
	return 0;
}