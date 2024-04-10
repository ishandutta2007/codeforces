#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int n, a[16], ans;

void dg(int x, int y) {
	if(x > n) {
		if(y % 360 == 0) ans = 1;
		return;
	}
	dg(x + 1, y + a[x]);
	dg(x + 1, y - a[x]);
}
int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	dg(1, 0);
	printf("%s", ans ? "YES" : "NO");
}