#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int a[140000][4], pre[140000][4], suf[140000][4];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
	}
	pre[0][0] = pre[0][1] = -INF;
	pre[0][2] = pre[0][3] = INF;
	
	pre[1][0] = a[1][0], pre[1][1] = a[1][1],
	pre[1][2] = a[1][2], pre[1][3] = a[1][3];
	for(int i=2;i<n;i++) {
		pre[i][0] = max(pre[i-1][0], a[i][0]);
		pre[i][1] = max(pre[i-1][1], a[i][1]);
		pre[i][2] = min(pre[i-1][2], a[i][2]);
		pre[i][3] = min(pre[i-1][3], a[i][3]);
	}
	
	suf[n+1][0] = suf[n+1][1] = -INF;
	suf[n+1][2] = suf[n+1][3] = INF;
	
	suf[n][0] = a[n][0], suf[n][1] = a[n][1],
	suf[n][2] = a[n][2], suf[n][3] = a[n][3];
	for(int i=n-1;i>=1;i--) {
		suf[i][0] = max(suf[i+1][0], a[i][0]);
		suf[i][1] = max(suf[i+1][1], a[i][1]);
		suf[i][2] = min(suf[i+1][2], a[i][2]);
		suf[i][3] = min(suf[i+1][3], a[i][3]);
	}
	
	for(int i=1;i<=n;i++) {
		int x1, y1, x2, y2;
		x1 = max(pre[i-1][0], suf[i+1][0]);
		y1 = max(pre[i-1][1], suf[i+1][1]);
		x2 = min(pre[i-1][2], suf[i+1][2]);
		y2 = min(pre[i-1][3], suf[i+1][3]);
		if(x1 <= x2 && y1 <= y2) {
			cout << x1 << " " << y1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}