#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//typedef pair<int, int> pii;

struct pii {
	int first, second;
	bool contains(const int a) const {
		return a == first || a == second;
	}
};

int solve(vector<pii>& a, vector<pii>& b) {
	set<int> matching_nums;
	for(const auto& aa : a) {
		for(const auto& bb : b) {
			if(bb.contains(aa.first) ^ bb.contains(aa.second)) {
				matching_nums.insert(bb.contains(aa.first) ? aa.first : aa.second);
			}
		}
	}
	if(matching_nums.size() == 0) return -1;
	if(matching_nums.size() == 1) return *matching_nums.begin();
	return -2;
}

bool is_bad(vector<pii>& a, vector<pii>& b) {
	for(const auto& aa : a) {
		pair<bool, bool> has_match(false, false);
		for(const auto& bb : b) {
			if(bb.contains(aa.first) ^ bb.contains(aa.second)) {
				has_match.first |= (bb.contains(aa.first));
				has_match.second |= (bb.contains(aa.second));
			}
		}
		if(has_match.first && has_match.second) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<pii> a(N), b(M);
	for(auto& ii : a) cin >> ii.first >> ii.second;
	for(auto& ii : b) cin >> ii.first >> ii.second;
	int s = solve(a, b);
	if(s > -2) {
		cout << s << endl;
		return 0;
	}
	s = solve(b, a);
	if(s > -2) {
		cout << s << endl;
		return 0;
	}
	bool bad = is_bad(a, b) || is_bad(b, a);
	if(bad) cout << -1 << endl;
	else cout << 0 << endl;
	
	return 0;
}