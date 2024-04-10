#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

// 
long long M;
long long N, A[1 << 19], B[1 << 19];

// 
long long D[1 << 19], X[1 << 19];

// 
long long Answer = 0;
long long num[1 << 19];

long long solve(long long pos) {
	long long sum = 0;
	for (int i = 0; i < N * 2; i++) {
		sum += abs(X[i] - pos) * D[i];
	}
	return sum;
}

int main() {
	//  1. 
	scanf("%lld%lld", &M, &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &B[i]);

	//  2. 
	vector<pair<long long, int>> vec;
	for (int i = 1; i <= N; i++) vec.push_back(make_pair(A[i], -i));
	for (int i = 1; i <= N; i++) vec.push_back(make_pair(B[i], i));
	sort(vec.begin(), vec.end());

	//  3. 
	for (int i = 0; i < vec.size(); i++) {
		X[i + 1] = X[i];
		if (vec[i].second < 0) X[i + 1] += 1;
		if (vec[i].second > 0) X[i + 1] -= 1;
	}
	for (int i = 1; i < vec.size(); i++) D[i] = vec[i].first - vec[i - 1].first;
	D[0] = (vec[0].first - vec[vec.size() - 1].first) + M;

	//  4. 
	long long cl = 0, cr = 0, d1, d2;
	for (int i = 0; i < vec.size(); i++) {
		cl = min(cl, X[i]);
		cr = max(cr, X[i]);
	}
	int el = cl, er = cr;
	for (int i = 0; i < 77; i++) {
		d1 = (cl + cl + cr) / 3;
		d2 = (cl + cr + cr) / 3;
		long long v1 = solve(d1);
		long long v2 = solve(d2);
		if (v1 > v2) { cl = d1; }
		else { cr = d2; }
	}
	long long minx = (1LL << 60), ret = 0;
	for (int i = cl - 5; i <= cr + 5; i++) {
		if (i < el || er < i) continue;
		long long val = solve(i);
		if (minx > val) { minx = val; ret = i; }
	}

	//  5. 
	int pos = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (X[i] == ret) { pos = i; break; }
	}
	vector<int> D1, D2;
	for (int i = pos; i < pos + vec.size(); i++) {
		if (vec[i % vec.size()].second < 0) D1.push_back(-vec[i % vec.size()].second);
		if (vec[i % vec.size()].second > 0) D2.push_back(vec[i % vec.size()].second);
	}
	for (int i = 0; i < D1.size(); i++) {
		Answer += min(abs(A[D1[i]] - B[D2[i]]), M - abs(A[D1[i]] - B[D2[i]]));
		num[D1[i]] = D2[i];
	}

	//  6. 
	printf("%lld\n", Answer);
	for (int i = 1; i <= N; i++) { if (i >= 2) printf(" "); printf("%lld", num[i]); }
	printf("\n");
	return 0;
}