#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int mod = 1e9 + 7;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1) c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int q;
char s[100001];
int type, n;

vector <tuple<int,int,int>> query;
int ans[100001];

int fac[100001];
int rev[100001];
int p25[100001];
int p26[100001];

int res[100001];

int newton(int N, int K) {
	int x = fac[N];
	x = 1ll * x * rev[K] % mod;
	x = 1ll * x * rev[N - K] % mod;
	return x;
}

void solve(int N) {
	for(int i = 0; i <= 100000; ++i)
		res[i] = 0;
	int prev = 0;
	for(int i = N; i <= 100000; ++i) {
		prev = 1ll * prev * 26 % mod;
		int k = i - N;
		prev = (prev + 1ll * p25[k] * newton(N + k - 1, N - 1) % mod) % mod;
		res[i] = prev;
	}
}
	

int main() {
	
	fac[0] = 1;
	rev[0] = 1;
	p25[0] = 1;
	p26[0] = 1;
	for(int i = 1; i <= 100000; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
		p25[i] = 1ll * p25[i - 1] * 25 % mod;
		p26[i] = 1ll * p26[i - 1] * 26 % mod;
	}
	
	scanf("%d", &q);
	scanf("%s", s);
	n = strlen(s);
	int z = 0;
	while(q--) {
		scanf("%d", &type);
		if(type == 1) {
			scanf("%s", s);
			n = strlen(s);
		}
		else {
			int y;
			scanf("%d", &y);
			query.pb({n, y, ++z});
		}
	}
	
	sort(query.begin(), query.end());
	for(int i = 0; i < ss(query);) {
		solve(get<0>(query[i]));
		int j = i;
		while(j < ss(query) && get<0>(query[i]) == get<0>(query[j])) {
			ans[get<2>(query[j])] = res[get<1>(query[j])];
			j += 1;
		}
		i = j;
	}
	
	for(int i = 1; i <= z; ++i)
		printf("%d\n", ans[i]);
	
	return 0;
}