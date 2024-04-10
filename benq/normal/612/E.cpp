#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
int n, p[1000001], ans[1000001];
bool done[1000001];
vector<vi> cycles[1000001];

void mc(int k) {
	vi x;
	int cur = k;
	x.pb(cur), done[cur] = 1;
	while(p[cur] != k) cur = p[cur], x.pb(cur), done[cur] = 1;
	cycles[x.size()].pb(x);
}

int main() {
	scanf("%d",&n);
	FOR(i,1,n+1) scanf("%d",&p[i]);
	FOR(i,1,n+1) if (!done[i]) mc(i);
	for (int i = n; i > 0; --i) {
		if (i % 2 == 0) {
			if (cycles[i].size() % 2 == 0) F0R(j,cycles[i].size()/2) F0R(k,i) ans[cycles[i][2*j][k]] = cycles[i][2*j+1][k], ans[cycles[i][2*j+1][k]] = cycles[i][2*j][(k+1) % i];
			else {
				cout << -1; 
				return 0;
			}
		} else F0R(j,cycles[i].size()) F0R(k,i) ans[cycles[i][j][k]] = cycles[i][j][(k+(i+1)/2) % i];
	}
	FOR(i,1,n+1) printf("%d ",ans[i]);
}