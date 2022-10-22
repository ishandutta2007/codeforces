#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)
 
using ll = long long;
using namespace std;

const int N = 1e5 + 5;
const int B = (int)sqrt(9999);
const int M = 99991;

int n;
bool sieve[N], killed[N], blocked[N];
vector <int> prime[2];

//~ void block(int x) {
	//~ rep(i, 1, n / x)
		//~ if (i * x != M)
			//~ blocked[i * x] = true;
//~ }

//~ int cnt(int x) {
	//~ int r = 0;
	//~ rep(i, 1, n / x)
		//~ r += !blocked[i * x];
	//~ return r;
//~ }

int ask(char c, ll a) {
	if (a > n) return 0;
	printf ("%c %lld\n", c, a);
	fflush(stdout);
	if (c == 'C') exit(0);
	int x;
	scanf ("%d", &x);
	return x;
	//~ int ans = cnt(a);
	//~ if (c == 'B')
		//~ block(a);
	//~ return ans;
}

void kill(int x) {
	rep(i, 1, n / x)
		killed[i * x] = true;
}		

int count() {
	int r = 0;
	rep(i, 1, n)
		r += !killed[i];
	return r;
}

int main() {
	scanf ("%d", &n);
	rep(i, 2, n) {
		if (!sieve[i]) {
			if (ll(i) * i <= n) prime[0].pb(i);
			else prime[1].pb(i);
			rep(j, 1, n / i)
				sieve[i * j] = true;
		}
	}
	int alert = (int)prime[1].size();
	
	rep(i, 0, (int)prime[1].size() - 1) {	
		ask('B', prime[1][i]);
		kill(prime[1][i]);
		
		if ((i % B == 0 || i + 1 == (int)prime[1].size()) && alert == (int)prime[1].size()) 
			if (ask('A', 1) != count())
				alert = i;
	}
	
	int out = 1;
		
	if (alert < (int)prime[1].size()) {
		per(i, 0, alert) {
			int x = prime[1][i];
			ll y = x;
			while (ask('A', y) != 0) {
				out *= x;
				y *= x;
			}
			if (out != 1) break;
		}
	}
		
	for (auto x : prime[0]) {
		ask('B', x);
		ll y = x;
		while (ask('A', y) != 0) {
			out *= x;
			y *= x;
		}
	}	
	ask('C', out);	
	return 0;
}