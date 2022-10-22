#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
	int gx = -1e5, lx = 1e5, gy = -1e5, ly = 1e5;
	int n;
	scanf ("%d" ,&n);
	while (n--) {
		int x,y;
		scanf ("%d %d",&x,&y);
		int a,b,c,d;
		scanf ("%d %d %d %d",&a,&b,&c,&d);
		if (a == 0) gx = max(gx,x);
		if (b == 0) ly = min(ly,y);
		if (c == 0) lx = min(lx,x);
		if (d == 0) gy = max(gy,y);
	}
	if (gy > ly || gx > lx) return (void) printf ("0\n");
	printf ("1 %d %d\n",gx,gy);
}
int main() {
    int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}