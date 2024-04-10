#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)

int n, k, p, x, y;
int a[1000];

void solve()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int sum = 0;
	cin>>n>>k>>p>>x>>y;
	FOR(i, k) {cin>>a[i]; sum += a[i];}
	if (sum + n - k > x) {cout<<"-1"; return;}
	FOR2(median, y, p + 1){
		int nLess = 0, nEqual = 0;
		FOR(i, k) {if (a[i] < median) nLess++; if (a[i] == median) nEqual++;}
		if (nLess >= (n + 1) / 2) continue;
		int minLess = MAX((n - 1) / 2 - nLess - nEqual, 0);
		int maxLess = MIN((n - 1) / 2 - nLess, n - k);
		FOR2(nrLess, minLess, maxLess + 1){
			if (sum + nrLess + (n - nrLess - k) * median > x) continue;
			FOR(i, n - k - nrLess) cout<<median<<" ";
			FOR(i, nrLess) cout<<1<<" "; return;
		}
	}
	cout<<"-1";
}

int main()
{
	solve();
	return 0;
}