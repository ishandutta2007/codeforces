#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pii pair <int, int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
char grid[1000][1000];
int n,m, xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};
ll d[3][1000][1000], d1,d2,d3;
queue<pair<pii,int>> q;

bool ok(pii a) {
	if (a.f<0 || a.f > m-1 || a.s<0 || a.s>n-1 || grid[a.f][a.s] == '#') return false;
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	F0R(i,n) F0R(j,m) cin >> grid[j][i];
	
	F0R(k,3) {
		F0R(i,n) F0R(j,m) if (grid[j][i] == char('1'+k)) d[k][j][i] = -1, q.push(mp(mp(j,i),0));
		else d[k][j][i] = MOD;
		while (!q.empty()) {
			pair<pii,int> x = q.front();
			q.pop();
			d[k][x.f.f][x.f.s] = x.s;
			F0R (i,4) {
				int x1 = x.f.f+xd[i], y1 = x.f.s+yd[i];
				if (ok(mp(x1,y1)) && x.s+1<d[k][x1][y1]) d[k][x1][y1] = -1, q.push(mp(mp(x1,y1),x.s+1));
			}
		}
	}
	d1 = MOD, d2 = MOD, d3 = MOD;
	F0R(i,n) F0R(j,m) {
		if (grid[j][i] == '2') d3 = min(d3,d[0][j][i]-1), d1 = min(d1,d[2][j][i]-1);
		else if (grid[j][i] == '3') d2 = min(d2,d[0][j][i]-1);
	}
	
	ll ans = MOD;
	F0R(i,n) F0R(j,m) if (grid[j][i] == '.') ans = min(ans,d[0][j][i]+d[1][j][i]+d[2][j][i]-2);
	ans = min(ans,d1+d2+d3-max(max(d1,d2),d3));
	if (ans < MOD/2) cout << ans;
	else cout << -1;
	return 0;
}