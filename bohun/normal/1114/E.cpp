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

int Q = 60;

int get(int x) {
	Q--;
	printf("? %d\n", x);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

int wie(int x) {
	Q--;
	printf("> %d\n", x);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

unsigned ll myrand() {
	unsigned ll r = 1;
	for(int i = 0; i <= 10; ++i)
		r *= rand();
	r ^= (1LL << 56);
	r ^= (1LL << 32);
	r ^= (1LL << 14);
	return r;
}

map <int, int> mam;
			
int main() {
	srand(2137);
	int n;
	scanf("%d", &n);
	int l = 0;
	int r = 1e9;
	while(l < r) {
		int m = (l + r) / 2;
		if(wie(m) == 1)
			l = m + 1;
		else
			r = m;
	}
	
	vector <int> v;
	v.pb(l);
	
	Q = min(Q, n);
	
	while(Q > 0) {
		int r = myrand() % n + 1;
		while(mam[r] == 1) {
			r = myrand() % n + 1;
		}
		mam[r] = 1;
		v.pb(get(r));
	}
	int G = 0;
	for(int i = 0; i < ss(v); ++i)
		for(int j = 0; j < ss(v); ++j) {
			if(v[j] - v[i] != 0) {
				G = __gcd(G, abs(v[j] - v[i]));
			}
		}
	printf("! %d %d\n", l - G * (n - 1), G); 
	
	
	
	
	return 0;
}