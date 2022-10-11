#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
long double p[3]; int a, b, c, d, e;
int main() {
	cin >> a >> b >> c >> d >> e; if (a == 12)a = 0; if (d == 12)d = 0; if (e == 12)e = 0;
	p[0] = 1.0L*c / 60.0L;
	p[1] = 1.0L*(b * 60 + c) / 3600.0L;
	p[2] = 1.0L*(a * 3600 + b * 60 + c) / 43200.0L;
	sort(p, p + 3);
	int pos1 = lower_bound(p, p + 3, 1.0L*d / 12) - p; if (pos1 == 3)pos1 = 0;
	int pos2 = lower_bound(p, p + 3, 1.0L*e / 12) - p; if (pos2 == 3)pos2 = 0;
	if (pos1 == pos2)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}