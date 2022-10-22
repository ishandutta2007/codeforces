#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int nax = 1000000;
const int mod = 1e9 + 7;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int p[nax];
int K;

int find(int x) {
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void unia(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) {
		printf("NO\n");
		exit(0);
	}
	p[x] = y;
	K++;
}

set <pair<int,int>> s;
vector <int> add[nax];
vector <pair<int,int>> del[nax];
int n, l, r;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", &l, &r);
		add[l].pb(i);
		del[r].pb(mp(l, i));
		p[i] = i;
	}
	for(int i = 1; i <= 2 * n; ++i) {
		for(auto it : add[i])
			s.insert(mp(i, it));
			
		for(auto it : del[i]) {
			auto ele = s.upper_bound(mp(it.fi, 0)); 
			while(ele != s.end()) {
				if(ele->se == it.se) {
					ele++;
					continue;
				}
				if(*ele != it) {
					unia(ele->se, it.se);
				}
				ele++;
			}
		}
		
		for(auto it : del[i])
			s.erase(it);
	}
	if(K == n - 1) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	


	return 0;
}