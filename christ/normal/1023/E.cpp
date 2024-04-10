#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
char ret[1005];
char s[15];
bool grid[505][505];
bool query (int x, int y, int x2, int y2) {
	printf ("? %d %d %d %d\n",x,y,x2,y2);
	fflush(stdout);
	scanf ("%s",s);
	return s[0] == 'Y';
}
int main () {
	int n;
	scanf ("%d",&n); int curx = 1, cury = 1;
	for (int i = 1; i < n; i++) {
		if (query(curx,cury+1,n,n)) ++cury, ret[i] = 'R';
		else ++curx, ret[i] = 'D';
	}
	curx = n; cury = n;
	for (int i = 2 * n - 2; i >= n; i--) {
		if (query(1,1,curx-1,cury)) --curx, ret[i] = 'D';
		else --cury, ret[i] = 'R';
	}
	printf ("! %s\n",ret+1);
	return 0;
}