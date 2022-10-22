#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int n, k;
	cin >> n >> k;
	ld ans = 0;
	int x[n], y[n];
	cin >> x[0] >> y[0];
	for (int i = 1; i < n; i++){
		cin >> x[i] >> y[i];
		ans += sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
		cerr << sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1])) << endl;
	}
	cout << fixed << setprecision(7);
	cout << ans * k / 50;
}