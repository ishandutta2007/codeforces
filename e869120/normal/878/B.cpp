#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, M, A[1 << 18];

vector<int> solve(vector<int> vec) {
	vector<pair<int, int>> e;
	for (int i = 0; i < vec.size(); i++) {
		if (e.size() == 0 || e[e.size() - 1].first != vec[i]) e.push_back(make_pair(vec[i], 1));
		else {
			e[e.size() - 1].second += 1;
			if (e[e.size() - 1].second == K) e.pop_back();
		}
	}
	vector<int>f;
	for (int i = 0; i < e.size(); i++) {
		for (int j = 0; j < e[i].second; j++) f.push_back(e[i].first);
	}
	return f;
}

vector<pair<int, int>> compression(vector<int>vec) {
	vector<pair<int, int>> e;
	for (int i = 0; i < vec.size(); i++) {
		if (e.size() == 0 || e[e.size() - 1].first != vec[i]) e.push_back(make_pair(vec[i], 1));
		else {
			e[e.size() - 1].second += 1;
			if (e[e.size() - 1].second == K) e.pop_back();
		}
	}
	return e;
}

int main() {
	scanf("%lld%lld%lld", &N, &K, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

	vector<int> B1, B2;
	for (int i = 0; i < N * 1; i++) B1.push_back(A[i % N]);
	for (int i = 0; i < N * 2; i++) B2.push_back(A[i % N]);

	B1 = solve(B1);
	B2 = solve(B2);

	vector<pair<int, int>> E1 = compression(B1);

	bool flag = false;
	if (E1.size() % 2 == 0) flag = true;
	else {
		int cnt = 0;
		for (int i = 0; i < (int)E1.size() / 2; i++) {
			if (E1[i].first != E1[E1.size() - 1 - i].first || (E1[i].second + E1[E1.size() - 1 - i].second) % K != 0) break;
			cnt++;
		}
		if (cnt != (int)E1.size() / 2) flag = true;
	}

	if (flag == true) {
		long long S1 = (long long)B1.size(), S2 = (long long)B2.size();
		cout << S1 + (M - 1LL)*(S2 - S1) << endl;
	}
	else {
		long long BASE = (long long)B1.size() - 1LL * E1[E1.size() / 2].second;
		long long G = 1LL * E1[E1.size() / 2].second * M; G %= K;
		if (G == 0) cout << "0" << endl;
		else cout << BASE + G << endl;
	}
	return 0;
}