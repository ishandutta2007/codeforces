#include <iostream>
#include <map>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18], S, T;
map<long long, long long> Map;
vector<long long>vec;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]); S += A[i]; T += 1LL * (i - 1);
		Map[A[i]]++;
		if (Map[A[i]] >= 2) {
			vec.push_back(A[i]);
		}
	}
	if (vec.size() >= 2) {
		cout << "cslnb" << endl;
	}
	else if (vec.size() == 1 && (vec[0] == 0 || Map[vec[0] - 1] >= 1)) {
		cout << "cslnb" << endl;
	}
	else {
		if ((S - T) % 2 == 0) cout << "cslnb" << endl;
		else cout << "sjfnb" << endl;
	}
	return 0;
}