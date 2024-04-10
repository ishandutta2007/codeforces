#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000001;

bool p[INF];

int main()
{
	long long x;
	cin >> x;
	long long nx = x;
	long long mx = 1;
	for (long long i = 2; i * i <= nx; i++) {
		if (nx % i == 0) {
			mx = max(mx, i);
			while (nx % i == 0) nx /= i;
		}
	}
	mx = max(mx, nx);
	long long l = x - mx + 1;
	//vector<bool> p(INF, 1);
	for (int i = 0; i < INF; i++) p[i] = 1;
	p[0] = 0, p[1] = 0;
	for (long long i = 2; i < INF; i++) {
		for (long long j = i * i; j < INF; j += i) {
			p[j] = 0;
		}
	}
	long long ans = INF;
	for (long long i = 2; i < INF; i++) {
		if (p[i]) {
			if (x / i * i >= l && (l - 1) / i * i > 0) {
				ans = min(ans, (l - 1) / i * i + 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}