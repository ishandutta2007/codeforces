#include <iostream>
#define N (int)2e5+5
#define int long long

using namespace std;

int a[N], b[N];

signed main()
{
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	int y = 1, ct = 0;
	for(int i=1;i<=m;i++) {
		int x;
		cin >> x;
		x -= ct;
		while (x > a[y]) {
			ct += a[y];
			x -= a[y++];
		}
		
		cout << y << " " << x << endl;
	}
}