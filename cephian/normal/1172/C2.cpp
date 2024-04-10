#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const ll P = 998244353;

const int N = 2e5+5;
const int M = 3000+5;
int w[N];
int A = 0, B = 0;
ll stored[M*2];
bool t[N];

int d[M][M];
int n, m;

ll pw(ll a, int b) {
	if(b == 0) return 1;
	if(b&1) return a * pw(a, b-1) % P;
	ll t = pw(a,b/2);
	return t * t % P;
}

ll inv(ll a) {
	return pw(a, P-2);
}

inline ll choose_like(int a, int t, ll v) {
	if(B == 0 && a != t) return 0;
	if(a < 0) return 0;
	ll ans = ll(d[a][t]) * (A+a) % P;
	ans = ans * v % P;
	return ans;
}

inline ll choose_dislike(int a, int t, ll v) {
	if(B == 0) return 0;
	if(a > t) return 0;
	ll ans =  ll(d[a][t]) * (B-t+a) % P;
	//cout << -t+2*a << " and " << v << endl;
	ans = ans * v % P;
	return ans;
}

//A+B-t+2*a

ll gi(int a, int t) {
	if(a < 0 || a > t) return 0;
	return stored[m + (-t + 2*a)];
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> t[i];

	for(int i = 0; i < n; ++i) {
		cin >> w[i];
		if(t[i]) A += w[i];
		else B += w[i];
	}
	
	d[0][0] = 1;
	for(int i = -m; i <= m; ++i) {
		stored[m+i] = inv(A+B+i);
		//stored[m+i] = i;
	}
	for(int t = 1; t <= m; ++t) {
#pragma omp parallel for
		for(int a = 0; a <= t; ++a) {
			//ll v = stored[m+(2*a-t)];
			d[a][t] = (choose_like(a-1, t-1, gi(a-1, t-1)) + choose_dislike(a, t-1, gi(a, t-1))) % P;
		}
	}
	// find indep
	ll A_gen = 0;
	ll B_gen = 0;
	for(int a = 0; a <= m; ++a) {
		ll tmp = ll(d[a][m]) * (A+a) % P;
		A_gen = (A_gen + tmp) % P;

		tmp = ll(d[a][m]) * (B-(m-a)) % P;
		B_gen = (B_gen + tmp) % P;
	}

	A_gen = A_gen * inv(A) % P;
	B_gen = B_gen * inv(B) % P;

	for(int i = 0; i < n; ++i) {
		if(t[i] == 0) {
			cout << w[i] * B_gen % P << "\n";
		} else {
			cout << w[i] * A_gen % P << "\n";
		}
	}
}