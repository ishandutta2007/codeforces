#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;

long long a[1001], b[1001], c[1001], d[1001];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

pair<int, int> ok(int i, int j) {
	long long A1 = b[i] - d[i], A2 = b[j] - d[j],
		B1 = c[i] - a[i], B2 = c[j] - a[j],
		C1 = a[i] * d[i] - c[i] * b[i],
		C2 = a[j] * d[j] - c[j] * b[j];
	long long D = A1 * B2 - B1 * A2,
		Dx = B1 * C2 - C1 * B2,
		Dy = C1 * A2 - A1 * C2;
	if(D && Dx % D == 0 && Dy % D == 0) {
		int lb1 = min(a[i], c[i]);
		int rb1 = max(a[i], c[i]);
		int lb2 = min(a[j], c[j]);
		int rb2 = max(a[j], c[j]);
		int lb3 = min(b[i], d[i]);
		int rb3 = max(b[i], d[i]);
		int lb4 = min(b[j], d[j]);
		int rb4 = max(b[j], d[j]);
		int cx = Dx / D, cy = Dy / D;
		if(cx >= lb1 && cx <= rb1 && cx >= lb2 && cx <= rb2 &&
		   cy >= lb3 && cy <= rb3 && cy >= lb4 && cy <= rb4)
			return {cx, cy};
	} 
	return {INF, INF};
} 

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		int m = abs(a[i] - c[i]), k = abs(b[i] - d[i]), ct;
		if(m == 0) {
			ct = k + 1;
		} else if(k == 0) {
			ct = m + 1;
		} else
			ct = gcd(m, k) + 1;
		set<pair<int, int>> s;
		for(int j=0;j<i;j++) {
			pair<int, int> tmp = ok(i, j);
			if(tmp.first != INF) {
				s.insert(tmp);
			}
		}
		ans += ct - s.size();
	}
	cout << ans << endl;
}