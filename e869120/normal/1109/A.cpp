#include <iostream>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

map<long long, long long>M;
long long N, A[1 << 19], B[1 << 19], ret;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) B[i] = (B[i - 1] ^ A[i]);

	M[0] = 1;
	for (int i = 2; i <= N; i += 2) {
		ret += M[B[i]]; M[B[i]]++;
	}
	M.clear();
	M[B[1]] = 1;
	for (int i = 3; i <= N; i += 2) {
		ret += M[B[i]]; M[B[i]]++;
	}
	cout << ret << endl;
	return 0;
}