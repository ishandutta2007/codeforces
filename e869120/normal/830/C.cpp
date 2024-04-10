#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
using namespace std;
long long n, k, a[100], s; vector<pair<int, int>>F;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j <= 20000; j++) {
			long long I = (a[i] + j - 1) / j;
			if (I >= 50000) {
				long long Y = 0;
				if (a[i] % (I - 1) != 0)Y = (I - 1) - (a[i] % (I - 1));
				long long Z = 0;
				if (a[i] % I != 0)Z = I - (a[i] % I);
				F.push_back(make_pair(I, Y - Z + j));
			}
		}
	}
	sort(F.begin(), F.end());
	long long c;
	for (int i = 1; i < 50000; i++) {
		long long cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] % i != 0)cnt += (i - (a[j] % i));
		}
		if (cnt <= k) { s = i; }
		c = cnt;
	}
	long long E = 0;
	for (int i = 0; i < n; i++)E += ((a[i] - 1) / 49999) + 1;
	if (c <= k)s = max(s, (k - c) / E + 49999);
	if (F.size() >= 1)c += E*(F[0].first - 50000);
	for (int i = 0; i < F.size(); i++) {
		E--; c -= F[i].second;
		if (i == F.size() - 1 || F[i].first != F[i + 1].first) {
			if (c + E <= k)s = max(s, F[i].first + (k - (c + E)) / E);
			if (i != F.size() - 1)c += E*(F[i + 1].first - F[i].first);
		}
	}
	cout << s << endl;
	return 0;
}