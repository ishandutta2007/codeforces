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

const int nax = 200005;

int p[nax];
int maxi[nax];
vector <int> nodes[nax];

int find(int x) {
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void unia(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		if(ss(nodes[x]) > ss(nodes[y]))
			swap(x, y);
		p[x] = y;
		for(auto it: nodes[x])
			nodes[y].pb(it);
		maxi[y] = max(maxi[y], maxi[x]);
	}
}

int n, m, a, b;

int alive[nax];
int wsk = 1;

void akt() {
	while(!alive[wsk])
		wsk += 1;
}
	

int main() {
	scanf("%d %d", &n, &m);
	FOR(i, n) {
		nodes[i].pb(i);
		maxi[i] = i;
		p[i] = i;
		alive[i] = 1;
	}
	alive[n + 1] = 1;
	FOR(i, m) {
		scanf("%d %d", &a, &b);
		unia(a, b);
	}
	int ans = 0;
	FOR(i, n) {
		if(!alive[i])
			continue;
		for(auto it : nodes[find(i)])
			alive[it] = 0;
		akt();
		while(wsk <= maxi[find(i)]) {
			for(auto it : nodes[find(wsk)])
				alive[it] = 0;
			unia(i, wsk);
			akt();
			ans += 1;
		}
	}
	printf("%d", ans);
		
			
		
			
		
		
	
	
	
	return 0;
}