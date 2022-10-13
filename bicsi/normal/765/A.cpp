#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	set<string> Set;

	int n;
	string home;
	cin >> n >> home;
	while(n--) {
		string big;
		cin >> big;

		string small[2];
		int now = 0;
		for(auto &c : big) {
			if(c == '-' || c == '>')
				now = 1;
			else small[now] += c;
		}

		if(small[1] == home) swap(small[0], small[1]);

		if(Set.find(small[1]) == Set.end())
			Set.insert(small[1]);
		else assert(Set.erase(small[1]));
	}

	if(Set.empty()) cout << "home\n";
	else {
		assert(Set.size() == 1);
		cout << "contest\n";
	}

	return 0;
}