#include <iostream>
#include <cmath>
using namespace std;

long long n, x1, x2, yy1, y2;

long long a[2001][2], ans = pow(2,63)-1;

int main() {
	cin >> n >> x1 >> yy1 >> x2 >> y2;
	for (int i = 0; i < n; ++i) {
		long long j,k;
		cin >> j >> k;
		a[i][0] = (x1-j)*(x1-j)+(yy1-k)*(yy1-k);
		a[i][1] = (x2-j)*(x2-j)+(y2-k)*(y2-k);
	}
	for (int i = 0; i <= n; ++i) {
		long long temp = a[i][0], temp2=0;
		for (int j = 0; j <= n; ++j) {
			if (temp < a[j][0] && a[j][1] > temp2) temp2 = a[j][1];
		} 
		if (temp+temp2<ans) ans=temp+temp2;
	}
	cout << ans;
}