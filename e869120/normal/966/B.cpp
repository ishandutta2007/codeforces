#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long n, x1, x2; vector<pair<long long,long long>>vec;

int main() {
	cin >> n >> x1 >> x2;
	for (int i = 1; i <= n; i++) {
		long long c; scanf("%lld", &c);
		vec.push_back(make_pair(c, i));
	}
	sort(vec.begin(), vec.end(), greater<pair<long long,long long>>());
	for (int i = 0; i < 2; i++) {
		long long c1 = 0, c2 = 0, L = 0;
		for (int j = 0; j < vec.size(); j++) {
			if (L == 0) {
				c1++;
				if (vec[j].first*c1 >= x1) { L = 1; }
			}
			else {
				c2++;
				if (vec[j].first*c2 >= x2) { L = 2; }
			}
			if (L == 2) break;
		}
		if (L == 2) {
			if (i == 0) {
				cout << "Yes" << endl;
				cout << c1 << " " << c2 << endl;
				for (int j = 0; j < c1; j++) { if (j) printf(" "); printf("%lld", vec[j].second); }cout << endl;
				for (int j = 0; j < c2; j++) { if (j) printf(" "); printf("%lld", vec[c1 + j].second); }cout << endl;
			}
			else {
				cout << "Yes" << endl;
				cout << c2 << " " << c1 << endl;
				for (int j = 0; j < c2; j++) { if (j) printf(" "); printf("%lld", vec[c1 + j].second); }cout << endl;
				for (int j = 0; j < c1; j++) { if (j) printf(" "); printf("%lld", vec[j].second); }cout << endl;
			}
			return 0;
		}
		swap(x1, x2);
	}
	cout << "No" << endl;
	return 0;
}