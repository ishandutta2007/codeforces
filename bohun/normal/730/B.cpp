#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

int T;
int n;
vector <int> maxi, mini;

int zap(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char c;
	scanf(" %c", &c);
	return (c == '=' || c == '>');
}

int main() {	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		maxi.clear();
		mini.clear();
		for(int i = 1; i + 1 <= n; i += 2) {
			if(zap(i, i + 1)) {
				maxi.pb(i);
				mini.pb(i + 1);
			}
			else {
				mini.pb(i);
				maxi.pb(i + 1);
			}
		}
		if(n % 2 == 1) {
			maxi.pb(n);
			mini.pb(n);
		}
		for(int i = 1; i < ss(maxi); ++i)
			if(zap(maxi[i], maxi[0]))
				maxi[0] = maxi[i];
		for(int i = 1; i < ss(mini); ++i)
			if(!zap(mini[i], mini[0]))
				mini[0] = mini[i];
		printf("! %d %d\n", mini[0], maxi[0]);
		fflush(stdout);
	}
			
		
	
			
	return 0;
}