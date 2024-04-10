#include<bits/stdc++.h>
using namespace std;

using INT = long long;

int main() {
	int n; cin >> n;
	if(n % 4 == 2 || n % 4 == 3) return puts("NO"), 0;
	
	puts("YES");
	vector<pair<int, int> > ans;
	for(int i=1; i<n; i+=2) for(int j=i+2; j<n; j+=2) {
		ans.push_back({i, j});
		ans.push_back({i+1, j+1});
		ans.push_back({i+1, j});
		ans.push_back({i, j+1});
	}
	if(n % 4 == 0) {
		for(int i=1; i<n; i+=2) ans.push_back({i, i+1});
	} else {
		for(int i=1; i<n; i+=2) {
			ans.push_back({n, i});
			ans.push_back({i, i+1});
			ans.push_back({n, i+1});
		}
	}
	
	for(auto p : ans) {
		if(p.first > p.second) swap(p.first, p.second);
		printf("%d %d\n", p.first, p.second);
	}
}