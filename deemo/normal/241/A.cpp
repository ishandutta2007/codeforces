#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN];

int main(){
	int n, k;	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];
	int ans = 0, mx = 0, cur = 0;
	for (int i = 0; i < n; i++){
		mx = max(mx, b[i]);
		cur += b[i];

		int nd = max(0, a[i] - cur);
		nd = nd/ mx + bool(nd % mx);
		ans += nd * k;
		cur += mx * nd;
		
		ans += a[i];
		cur -= a[i];
	}
	cout << ans << endl;
	return 0;
}