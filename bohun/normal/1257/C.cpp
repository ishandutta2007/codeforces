#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

int n;
int T;
int a[200005]; 
map <int, int> mapa;
 
int main() {	
	scanf("%d", &T);
	while(T--) {
		mapa.clear();
		scanf("%d", &n);
		FOR(i, n) scanf("%d", a + i);
		int best = n + 1;
		FOR(i, n) {
			if(mapa.find(a[i]) != mapa.end())
				best = min(best, i - mapa[a[i]] + 1);
			mapa[a[i]] = i;
		}
		if(best == n + 1)
			printf("-1\n");
		else
			printf("%d\n", best);
	}
	
	
	return 0;
}