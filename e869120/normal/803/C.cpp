#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
long long n, k; bool flag = false;
int main() {
	cin >> n >> k; if (k >= 200000) { cout << "-1" << endl; return 0; }
	vector<long long>E;
	for (long long i = 1; i*i <= n; i++) { if (n%i == 0) { E.push_back(i); if (i != n / i)E.push_back(n / i); } }
	sort(E.begin(), E.end());
	for (int i = E.size() - 1; i >= 0; i--) {
		long long V = E[E.size() - 1 - i];
		long long Z = k*(k + 1) / 2;
		if (V < Z)continue;
		long long sum = n;
		for (long long j = 1; j < k; j++) { cout << j*E[i] << ' '; sum -= j*E[i]; }
		cout << sum << endl; flag = true; break;
	}
	if (flag == false)cout << "-1" << endl;
	return 0;
}