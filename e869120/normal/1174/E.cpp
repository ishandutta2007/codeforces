#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long mod = 1000000007;
long long N;

long long solve(vector<long long>E) {
	vector<long long>C; long long sum = 1, B = 0;
	for (int i = 0; i < E.size(); i++) {
		C.push_back((N / E[i]) - B); sum *= ((N / E[i]) - B); sum %= mod;
		B = (N / E[i]);
	}

	long long cx = 1;
	for (int i = (int)E.size() - 1; i >= 0; i--) {
		for (int j = 0; j < C[i] - 1; j++) { sum *= cx; sum %= mod; cx++; }
		cx++;
	}
	return sum;
}

int main() {
	cin >> N;
	vector<long long>V; V.push_back(1);
	while (V[V.size() - 1] * 2LL <= N) V.push_back(V[V.size() - 1] * 2LL);
	reverse(V.begin(), V.end());

	long long P1 = solve(V);
	long long sum = P1;

	if (3LL * V[0] <= 2LL * N) {
		for (int i = 1; i <= (int)V.size() - 1; i++) {
			vector<long long>V2 = V;
			for (int j = 0; j < i; j++) V2[j] = 3LL * V2[j] / 2LL;

			long long P2 = solve(V2);
			sum += P2; sum %= mod;
		}
	}
	cout << sum << endl;
	return 0;
}