#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 2e5 + 111;

int n, t, k;
int a[nax];
int lvl[nax];
int r[nax];
vector <pair<int,int>> res;
vector <int> ja, on;
int fre = 1;

int main() {
	scanf("%d %d %d", &n, &t, &k);
	FOR(i, 1, t) {
		scanf("%d", a + i + 1);
	}
	a[1] = 1;
	FOR(i, 2, t + 1) {
		lvl[i] = max(0, a[i] - a[i + 1]);
		r[i] = a[i] - lvl[i];
		k -= lvl[i];
	}	
	r[1] = 1;
	if(k < 0) {
		printf("-1\n");
		return 0;
	}
	ja.pb(fre++);
	FOR(i, 1, t) {
		on.clear();
		FOR(j, 1, a[i + 1])
			on.pb(fre++);
		int nom = r[i] - 1;
		nom = min(nom, k);
		k -= nom;
		nom = r[i] - nom;
		if(i == 1)
			nom = r[1];
		FOR(j, 0, nom - 1) {
			res.pb(mp(ja[j], on[j]));
		}
		FOR(j, nom, a[i + 1] - 1)
			res.pb(mp(ja[0], on[j]));
		ja = on;
	}
	if(k > 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n);
	for(auto it : res)
		printf("%d %d\n", it.fi, it.se);
			
		
		
	
	
	
	
	
	return 0;
}