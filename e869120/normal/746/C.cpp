#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
long double n, s, t, at, bt, p, d;
int main() {
	cin >> n >> s >> t >> at >> bt >> p >> d; if (d == -1)d = 0;
	if (at >= bt) {
		cout << (int)(abs(s - t)*bt) << endl;
	}
	if (at < bt) {
		if (s > t) { s = n - s; t = n - t; p = n - p; d = 1 - d; }
		if (s == t)cout << "0" << endl;
		else {
			long double D = p; if (d == 0)D = -p; if (s < p && d == 1)D = -2 * n + p;
			long double E = s + ((s - D) / ((bt - at) / at));
			if (t < E) { cout << (abs(s - t)*bt) << endl; }
			else { cout << (abs(s - E)*bt + abs(t - E)*at) << endl; }
		}
	}
	return 0;
}