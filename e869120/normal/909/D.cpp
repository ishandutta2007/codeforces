#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string S; set<int>Set; int n; vector<int>vec;

bool yabai(int pos) {
	auto itr = Set.lower_bound(pos);
	char L = S[pos], R = S[pos];
	auto itr2 = itr;
	if (itr != Set.end()) {
		itr++;
		if (itr != Set.end()) R = S[*itr];
	}
	if (itr2 != Set.begin()) {
		itr2--;
		L = S[*itr2];
	}
	if (L != S[pos] || S[pos] != R) return false;
	return true;
}

int main() {
	cin >> S; n = S.size();
	for (int i = 0; i < n; i++) { Set.insert(i); vec.push_back(i); }
	int cnt = 0;
	while (true) {
		vector<int>V;
		for (int i = 0; i < vec.size(); i++) {
			if (yabai(vec[i]) == false) V.push_back(vec[i]);
		}
		if (V.size() == 0) break;
		cnt++; vec.clear();
		for (int i = 0; i < V.size(); i++) Set.erase(V[i]);
		for (int i = 0; i < V.size(); i++) {
			auto itr = Set.lower_bound(V[i]);
			auto itr2 = itr;
			if (itr != Set.end()) {
				vec.push_back(*itr);
				itr++;
				if (itr != Set.end()) vec.push_back(*itr);
			}
			if (itr2 != Set.begin()) {
				itr2--; vec.push_back(*itr2);
			}
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}
	cout << cnt << endl;
	return 0;
}