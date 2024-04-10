/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

#define int long long

int n, m, k;

int sub(int a, int b, int mod) {
	a -= b;
	if(a < 0) a += mod;
	return a;
}
int mul(int a, int b, int mod) {
	return 1LL * a * b % mod;
}

int Shit(int c1, int c2, int a, int b, int mod) {
	// cerr << "Shit: " << c1 << " " << c2 << " " << a << " " << b << '\n';
	if(c1 == 1) {
		if(mul(a, c2, mod) != b)
			return 2e18 + 9;
		return a;
	}
	if(c1 > c2) return Shit(c2, c1, b, a, mod);

	// c1 <= c2
	// Scad din c2 c1 * cat pot
	int cat_pot = c2 / c1;
	return Shit(c1, c2 - cat_pot * c1, a, sub(b, mul(cat_pot, a, mod), mod), mod);
}

int Stuff(int b, int a, int p, int q) {
	// cerr << "DoStuff: " << a << " " << b << " " << p << " " << q << '\n';
	int gcd = __gcd(p, q);

	int ret = Shit(q / gcd, p / gcd, a * q / gcd, b * p / gcd, p / gcd * q);
	if(ret == 0) ret += p / gcd * q;
	return ret;
}

int Solve(int a, int b) {
	if(a == b) return a;
	if(m == n) return 2e18 + 7;

	return Stuff(a, b, 2 * m, 2 * n);
}

int SolveFor(int a, int b) {
	return min(
		min(Solve(a, b), Solve(a + 2 * (n - a), b)),
		min(Solve(a, b + 2 * (m - b)), Solve(a + 2 * (n - a), b + 2 * (m - b)))
	);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= k; ++i) {
		int a, b;
		cin >> a >> b;
		int ret = SolveFor(a, b);

		if(ret >= 2e18)
			cout << -1 << '\n';
		else
			cout << ret << '\n';
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/