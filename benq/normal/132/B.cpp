#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

char grid[50][50];
int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};
map<pair<pii,pii>,int> tim;
pii cpos;
int d = 0, c = 1,m,n,m1;
bool f = 0;

void move() {
	while (1) {
		pii k = {cpos.f+xdir[d],cpos.s+ydir[d]};
		if (k.f < 0 || k.f >= m1 || k.s < 0 || k.s >= m) break;
		if (grid[k.f][k.s] != grid[cpos.f][cpos.s]) break;
		cpos = k;
	}
	while (1) {
		pii k = {cpos.f+xdir[c],cpos.s+ydir[c]};
		if (k.f < 0 || k.f >= m1 || k.s < 0 || k.s >= m) break;
		if (grid[k.f][k.s] != grid[cpos.f][cpos.s]) break;
		cpos = k;
	}
	pii k = {cpos.f+xdir[d],cpos.s+ydir[d]};
	bool p = 1;
	if (k.f < 0 || k.f >= m1 || k.s < 0 || k.s >= m) p = 0;
	if (grid[k.f][k.s] == '0') p = 0;
	if (p) cpos = k;
	else {
		if ((c-d-1) % 4 == 0) c = (d+3) % 4;
		else {
			d = (d+3) % 4;
			c = (d+1) % 4;
		}
	}
}	

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> m >> n; 
	cpos = {0,m-1};
	F0Rd(j,m) {
		string x; cin >> x;
		m1 = x.length();
		F0R(i,m1) grid[i][j] = x[i];
	}
	while (1) {
		if (!f && tim[{cpos,{d,c}}]) {
			int dif = tim[{cpos,{d,c}}] - n;
			while (n >= dif) n -= dif;
			f = 1;
		}
		if (n == 0) {
			cout << grid[cpos.f][cpos.s];
			return 0;
		}
		if (!f) tim[{cpos,{d,c}}] = n;
		move();
		n--;
	}
}