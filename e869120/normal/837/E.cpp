#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
long long x, y, r; vector<long long>E;
long long gcd(long long x, long long y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
long long func(long long x, long long y) {
	E.clear();
	for (long long i = 1; i*i <= x; i++) {
		if (x%i == 0) { E.push_back(i); E.push_back(x / i); }
	}
	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());
	r = gcd(x, y); long long cnt = 0;
	if (y%x == 0)return y / x;
	while (y > 0) {
		long long maxn = (1LL << 60), maxid = 0;
		for (int i = 0; i < E.size(); i++) {
			if (r >= E[i] || E[i] % r != 0)continue;
			long long B = (y%E[i]) / r;
			if (maxn >= B) { maxn = B; maxid = E[i]; }
		}
		y -= maxn*r; r = maxid; cnt += maxn; r = gcd(x, y);
		if (y%E[E.size() - 1] == 0) { cnt += y / E[E.size() - 1]; break; }
	}
	return cnt;
}
long long func2(long long x, long long y) {
	long long cnt = 0;
	while (y > 0) { cnt++; y -= gcd(x, y); }
	return cnt;
}
int main() {
	long long p1, p2; cin >> p1 >> p2;
	cout << func(p1, p2) << endl;
	return 0;
}