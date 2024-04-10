#include <iostream>
#include <string>
#include <set>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int Q, ret = 1, D[500000]; string S[500000]; char c[12];
set<int>up, down, tossup;

bool hantei(int x) {
	if (up.size() >= 1) {
		auto itr = up.begin();
		if (*itr < x) return false;
	}
	if (down.size() >= 1) {
		auto itr = down.end(); itr--;
		if (*itr > x) return false;
	}
	return true;
}

void moves(int x) {
	while (true) {
		auto itr = tossup.lower_bound(x + 1); if (itr == tossup.end()) break;
		up.insert(*itr);
		tossup.erase(itr);
	}
	while (true) {
		auto itr = tossup.lower_bound(-1); if (itr == tossup.end() || *itr == x) break;
		down.insert(*itr);
		tossup.erase(itr);
	}
}

int solve_Output() {
	up.clear(); down.clear(); tossup.clear(); ret = 1;
	for (int i = 1; i <= Q; i++) {
		if (S[i] == "ADD") {
			// add
			int cap = D[i];
			tossup.insert(cap);
		}
		if (S[i] == "ACCEPT") {
			// accept
			int cap = D[i];

			bool t = hantei(cap);
			if (t == false) {
				return 0;
			}

			moves(cap);

			auto itr = tossup.lower_bound(cap);
			if (itr != tossup.end() && *itr == cap) { ret *= 2; ret %= 1000000007; }
			up.erase(cap);
			down.erase(cap);
			tossup.clear();
		}
	}

	long long cntv = 0; auto itr1 = tossup.begin();
	int cl = -(1 << 30), cr = (1 << 30);
	if (down.size() >= 1) { auto itr = down.end(); itr--; cl = *itr; }
	if (up.size() >= 1) { auto itr = up.begin(); cr = *itr; }

	while (itr1 != tossup.end()) {
		int val = *itr1;
		if (cl <= val && val <= cr) cntv++;
		itr1++;
	}
	return (1LL * ret * (cntv + 1)) % 1000000007;
}

int solve_Jury() {
	int ans = 0;

	vector<int>vec;
	for (int i = 1; i <= Q; i++) { if (S[i] == "ADD") vec.push_back(i); }

	for (int i = 0; i < (1 << vec.size()); i++) {
		int bit[12]; for (int j = 0; j < vec.size(); j++) bit[j] = (i / (1 << j)) % 2;

		int cnt = 0; vector<int>buy, sell; bool flag = true;
		for (int j = 1; j <= Q; j++) {
			if (S[j] == "ADD") {
				if (bit[cnt] == 0) buy.push_back(D[j]);
				if (bit[cnt] == 1) sell.push_back(D[j]);
				cnt++;
			}
			if (S[j] == "ACCEPT") {
				bool ok = false;
				if (buy.size() >= 1 && buy[buy.size() - 1] == D[j]) ok = true;
				if (sell.size() >= 1 && sell[0] == D[j]) ok = true;

				if (ok == false) {
					flag = false; break;
				}

				vector<int>buy2, sell2;
				for (int k : buy) { if (k != D[j]) buy2.push_back(k); }
				for (int k : sell) { if (k != D[j]) sell2.push_back(k); }
				buy = buy2; sell = sell2;
			}
			sort(buy.begin(), buy.end());
			sort(sell.begin(), sell.end());

			if (buy.size() >= 1 && sell.size() >= 1 && buy[buy.size() - 1] > sell[0]) {
				flag = false; break;
			}
		}

		if (flag == true) ans++;
	}
	return ans;
}

void random_generate() {
	bool used[51]; for (int i = 1; i <= 50; i++) used[i] = false;

	Q = 8;
	for (int i = 1; i <= Q; i++) {
		while (true) {
			int u = rand() % 2, v = rand() % 50 + 1;
			if (u == 0 && used[v] == false) {
				used[v] = true;
				S[i] = "ADD"; D[i] = v;
				break;
			}
			if (u == 1 && used[v] == true) {
				used[v] = false;
				S[i] = "ACCEPT"; D[i] = v;
				break;
			}
		}
	}
}

int main() {
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%s%d", &c, &D[i]);
		if (c[1] == 'D') S[i] = "ADD";
		else S[i] = "ACCEPT";
	}
	cout << solve_Output() << endl;
	return 0;
}