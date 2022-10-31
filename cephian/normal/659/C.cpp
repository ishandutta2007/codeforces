#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

ll n,m;
set<int> has;
vector<int> ans;
ll spent = 0;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		has.insert(a);
	}

	for(int t = 1; ; ++t) {
		if(has.count(t)) continue;
		if(t+spent > m) break;
		spent += t;
		ans.push_back(t);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if(i != ans.size()-1) cout << " ";
	}
	cout << "\n";
	return 0;
}