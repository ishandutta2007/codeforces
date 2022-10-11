#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

vector<pair<long long, long long>>vec;
map<pair<long long, long long>, long long> M;

pair<long long, long long> Fraction(long long a, long long b) {
	long long e = gcd(abs(b), abs(a));
	a /= e; b /= e;
	if (b < 0) { b *= -1; a *= -1; }
	return make_pair(a, b);
}

long long N, A[1 << 18], B[1 << 18];

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++) scanf("%lld", &B[i]);

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			if (B[i] == 0) sum++;
		}
		else {
			pair<long long, long long> V = Fraction(B[i], A[i]);
			M[V]++; vec.push_back(V);
		}
	}
	
	long long maxn = 0;
	for (int i = 0; i < vec.size(); i++) maxn = max(maxn, M[vec[i]]);
	cout << sum + maxn << endl;
	return 0;
}