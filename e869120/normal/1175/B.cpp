#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string S[100009]; int n, p[100009];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		if (S[i] == "for") scanf("%d", &p[i]);
	}

	long long sum = 0; vector<long long> E;
	E.push_back(1);
	for (int i = 1; i <= n; i++) {
		if (S[i] == "for") {
			E.push_back(1LL * E[E.size() - 1] * p[i]);
			if (E[E.size() - 1] >= (1LL << 32)) E[E.size() - 1] = (1LL << 32);
		}
		if (S[i] == "add") {
			sum += E[E.size() - 1];
		}
		if (S[i] == "end") E.pop_back();
	}
	if (sum >= (1LL << 32)) cout << "OVERFLOW!!!" << endl;
	else cout << sum << endl;
	return 0;
}