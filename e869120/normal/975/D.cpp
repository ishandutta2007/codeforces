#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

vector<long long>vec; map<long long, long long>M1; map<pair<long long, long long>, long long>M2;
long long n, a, b, x[200009], vx[200009], vy[200009], sum;

int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &x[i], &vx[i], &vy[i]);
		vec.push_back(a*vx[i] - vy[i]);
		M1[vec[i - 1]]++;
		M2[make_pair(vx[i], vy[i])]++;
	}
	for (int i = 1; i <= n; i++) {
		sum += (M1[vec[i - 1]] - 1);
		sum -= (M2[make_pair(vx[i], vy[i])] - 1);
	}
	cout << sum << endl;
	return 0;
}