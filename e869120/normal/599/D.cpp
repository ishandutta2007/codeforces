#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n, num[5000000], s; vector<pair<long long, long long>>I;
int main() {
	cin >> n;
	for (long long i = 1; i < 5000000; i++) {
		num[i] = num[i - 1] + i*i;
		if (num[i] > n) { s = i - 1; break; }
	}
	for (long long i = 1; i <= s; i++) {
		long long B = i*(i + 1) / 2;
		if ((n - num[i]) % B == 0) { I.push_back(make_pair(i, i + (n - num[i]) / B)); I.push_back(make_pair(i + (n - num[i]) / B, i)); }
	}
	sort(I.begin(), I.end()); I.erase(unique(I.begin(), I.end()), I.end()); cout << I.size() << endl;
	for (int i = 0; i < I.size(); i++)cout << I[i].first << ' ' << I[i].second << endl;
	return 0;
}