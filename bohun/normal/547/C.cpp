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

const int nax = 5e5 + 111;

int n, q;
int a[nax];
int b;

bool sito[nax];
vector <int> p[nax];
int c[nax];
int gao[nax];

ll ans;

int main() {
	for(int i = 2; i < nax; ++i) {
		if(!sito[i]) {
			for(int j = i; j < nax; j += i) {
				sito[j] = 1;
				p[j].pb(i);
			}
		}
	}
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
		
	int akt = 0;
	while(q--) {
		scanf("%d", &b);
		c[b] ^= 1;
		if(c[b] == 0) {
			for(int mask = 0; mask < (1 << ss(p[a[b]])); ++mask) {
				int x = 1;
				for(int j = 0; j < ss(p[a[b]]); ++j)
					if(((mask >> j) & 1))
						x *= p[a[b]][j];
				gao[x]--;
			}
			akt--;
		}
		int dod = 0;
		for(int mask = 1; mask < (1 << ss(p[a[b]])); ++mask) {
			int x = 1;
			for(int j = 0; j < ss(p[a[b]]); ++j)
				if(((mask >> j) & 1))
					x *= p[a[b]][j];
			dod += gao[x] * (ss(p[x]) % 2 == 1 ? 1 : -1);
		}
		
		ans += (akt - dod) * (c[b] ? 1 : -1);
		
		if(c[b] == 1) {
			for(int mask = 0; mask < (1 << ss(p[a[b]])); ++mask) {
				int x = 1;
				for(int j = 0; j < ss(p[a[b]]); ++j)
					if(((mask >> j) & 1))
						x *= p[a[b]][j];
				gao[x]++;
			}
			akt++;
		}
		printf("%lld\n", ans);
	}
		
		
	
	
	
	
	return 0;
}