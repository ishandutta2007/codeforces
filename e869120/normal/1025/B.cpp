#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[200009], B[200009];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld%lld", &A[i], &B[i]);

	vector<long long>E;
	
	long long cx = A[0];
	for (long long i = 2; i*i <= cx; i++) {
		if (cx % i != 0) continue;
		E.push_back(i);
		while (cx%i == 0) cx /= i;
	}
	if (cx >= 2) E.push_back(cx);

	cx = B[0];
	for (long long i = 2; i*i <= cx; i++) {
		if (cx % i != 0) continue;
		E.push_back(i);
		while (cx%i == 0) cx /= i;
	}
	if (cx >= 2) E.push_back(cx);

	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());

	for (int i = 0; i < E.size(); i++) {
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (A[j] % E[i] != 0 && B[j] % E[i] != 0) { flag = false; break; }
		}
		if (flag == true) {
			cout << E[i] << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}