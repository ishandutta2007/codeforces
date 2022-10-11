#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N; vector<long long>vec;

int main() {
	cin >> N;
	for (long long i = 1; i*i <= N; i++) {
		if (N%i != 0) continue;
		vec.push_back(i);
		vec.push_back(N / i);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	vector<long long>S;
	for (int i = 0; i < vec.size(); i++) {
		long long D = N / vec[i];
		long long E = D + vec[i] * D * (D - 1LL) / 2LL;
		S.push_back(E);
	}
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());

	for (int i = 0; i < S.size(); i++) { if (i) cout << " "; cout << S[i]; } cout << endl;
	return 0;
}