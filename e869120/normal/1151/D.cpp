#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[200009], B[200009];
vector<tuple<long long, long long, long long>>tup;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		tup.push_back(make_tuple(B[i] - A[i], A[i], B[i]));
	}
	sort(tup.begin(), tup.end());
	long long cl = 0, cr = N - 1, s = 0;
	for (int i = 0; i < tup.size(); i++) {
		s += get<1>(tup[i]) * cl + get<2>(tup[i]) * cr;
		cl++; cr--;
	}
	cout << s << endl;
	return 0;
}