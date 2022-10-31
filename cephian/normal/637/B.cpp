#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<string> used;
vector<string> name;
vector<string> ans;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		name.push_back(s);
	}
	for(int i = n-1; i >=0; --i) {
		if(!used.count(name[i])) {
			ans.push_back(name[i]);
			used.insert(name[i]);
		}
	}
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";

	return 0;
}