#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long mod = 1145141919810893LL;
string A, B;
long long N, K, HA[1 << 19], HB[1 << 19], power[1 << 19];

int main() {
	cin >> N >> K >> A >> B;
	power[0] = 1LL; for (int i = 1; i < (1 << 19); i++) power[i] = (2LL * power[i - 1]) % mod;
	for (int i = 0; i < A.size(); i++) { HA[i + 1] = HA[i] * 2LL; if (A[i] == 'b') HA[i + 1] += 1; }
	for (int i = 0; i < B.size(); i++) { HB[i + 1] = HB[i] * 2LL; if (B[i] == 'b') HB[i + 1] += 1; }

	long long cnts = 0; bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (flag == true) {
			cnts += K;
		}
		else {
			long long D = HB[i] - HA[i] + 1LL; if (D < 0) D += mod;
			if (D >= K) { cnts += K; flag = true; }
			else cnts += D;
		}
	}
	cout << cnts << endl;
	return 0;
}