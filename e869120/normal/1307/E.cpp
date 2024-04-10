#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M;
long long S[1 << 18];
long long A[1 << 18], B[1 << 18];
long long L[1 << 18], R[1 << 18];

long long mod = 1000000007;
long long V1[1 << 18], V2[1 << 18], V3[1 << 18];

long long func(long long n) {
	return n * (n - 1) / 2;
}

pair<int, long long> solve(int pos) {
	for (int i = 1; i <= N; i++) { V1[i] = 0; V2[i] = 0; V3[i] = 0; }

	int cnt = 0; long long sum = 1;
	if (pos == 0) {
		for (int i = 1; i <= M; i++) {
			int cnts = 0;
			if (R[i] > L[pos]) cnts += 2;
			if (cnts == 1) V1[A[i]] += 1;
			if (cnts == 2) V2[A[i]] += 1;
			if (cnts == 3) V3[A[i]] += 1;
		}
	}
	else {
		cnt++;
		for (int i = 1; i <= M; i++) {
			if (i == pos) continue;
			int cnts = 0;
			if (L[i] <= L[pos]) cnts += 1;
			if (R[i] > L[pos]) cnts += 2;
			if (cnts == 1) V1[A[i]] += 1;
			if (cnts == 2) V2[A[i]] += 1;
			if (cnts == 3) V3[A[i]] += 1;
		}
		V2[A[pos]] += V3[A[pos]];
		V1[A[pos]] = 0;
		V3[A[pos]] = 0;
	}

	for (int i = 1; i <= N; i++) {
		// 2 
		long long t1 = 0;
		t1 = 2LL * func(V3[i]) + V2[i] * V3[i] + V1[i] * V3[i] + V1[i] * V2[i];
		if (t1 >= 1) { cnt += 2; sum *= t1; sum %= mod; }

		// 1 
		if (t1 == 0) {
			long long t2 = V1[i] + V2[i] + 2LL * V3[i];
			if (t2 >= 1) { cnt += 1; sum *= t2; sum %= mod; }
		}
	}
	return make_pair(cnt, sum);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		int cnt = 0; L[i] = (1LL << 60);
		for (int j = 1; j <= N; j++) {
			if (S[j] == A[i]) { cnt++; }
			if (cnt == B[i]) { L[i] = j; break; }
		}
		cnt = 0; R[i] = -(1LL << 60);
		for (int j = N; j >= 1; j--) {
			if (S[j] == A[i]) { cnt++; }
			if (cnt == B[i]) { R[i] = j; break; }
		}
	}

	pair<int, long long> ans = make_pair(-1, 0);
	for (int i = 0; i <= M; i++) {
		if (R[i] == -(1LL << 60)) continue;
		pair<int, long long> ret = solve(i);
		if (ans.first < ret.first) { ans.first = ret.first; ans.second = 0; }
		if (ans.first == ret.first) { ans.second += ret.second; ans.second %= mod; }
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}