#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> p(n+1);
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		if(i == p[i]) {
			cout << "YES\n";
			for(int j = 1; j <= n; ++j) {
				if(j != i)
					cout << i << " " << j << "\n";
			}
			cout << "\n";
			return 0;
		}
	}
	vector<vector<int>> cycles;
	vector<bool> seen(n);
	for(int i = 1; i <= n; ++i) {
		if(seen[i]) continue;
		vector<int> cyc(1, i);
		for(int j = p[i]; j != i; j = p[j]) {
			seen[j] = true;
			cyc.push_back(j);
		}
		if(cyc.size()%2 == 1) {
			cout << "NO\n";
			return 0;
		}
		cycles.push_back(cyc);
	}
	for(int i = 0; i < cycles.size(); ++i) {
		if(cycles[i].size() == 2) {
			cout << "YES\n";
			cout << cycles[i][0] << " " << cycles[i][1] << "\n";
			for(int j = 0; j < cycles.size(); ++j) {
				if(i == j) continue;
				for(int k = 0; k < cycles[j].size(); ++k) {
					if(k&1) cout << cycles[j][k] << " " << cycles[i][0] << "\n";
					else cout << cycles[j][k] << " " << cycles[i][1] << "\n";
				}
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;

}