#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int bit[1000000], size_;

//------------------------BIT-----------------------
void add(int s, int t) {
	while (s <= size_) { bit[s] += t; s += (s&-s); }
}
int sum(int p) {
	int s = 0; while (p >= 1) { s += bit[p]; p -= (p&-p); }return s;
}
int getMin() {
	int L = 0, R = size_ + 1, M;
	while(true) {
		M = (L + R) / 2;
		int p1 = sum(M - 1), p2 = sum(M);
		if (p1 == 0 && p2 >= 1)return M;
		if (p1 >= 1)R = M; else L = M;
	}
	return 0;
}

//-------------------------------MAIN------------------------
int n, c[100000], d[100000]; string S[100000]; vector<int>E; vector<pair<int, int>>F;
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> S[i]; if (S[i] != "removeMin") { cin >> c[i]; E.push_back(c[i]); d[i] = c[i]; } }
	sort(E.begin(), E.end()); size_ = E.size() + 2;
	for (int i = 0; i < n; i++) { c[i] = lower_bound(E.begin(), E.end(), c[i]) - E.begin(); c[i]++; }
	for (int i = 0; i < n; i++) {
		if (S[i] == "insert") { add(c[i], 1); F.push_back(make_pair(1, d[i])); }
		if (S[i] == "removeMin") {
			if (sum(size_) == 0) { F.push_back(make_pair(1, 1)); add(1, 1); }
			add(getMin(), -1); F.push_back(make_pair(3, 0));
		}
		if (S[i] == "getMin") {
			if (sum(c[i]) - sum(c[i] - 1) == 0) { add(c[i], 1); F.push_back(make_pair(1, d[i])); }
			while (sum(c[i] - 1) >= 1) { F.push_back(make_pair(3, 0)); add(getMin(), -1); }
			F.push_back(make_pair(2, d[i]));
		}
	}
	cout << F.size() << endl;
	for (int i = 0; i < F.size(); i++) {
		if (F[i].first == 1)cout << "insert " << F[i].second << endl;
		if (F[i].first == 2)cout << "getMin " << F[i].second << endl;
		if (F[i].first == 3)cout << "removeMin" << endl;
	}
	return 0;
}