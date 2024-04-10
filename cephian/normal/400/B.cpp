#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	set<int> S;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int x = 0;
		for(int j = 0; j < m; ++j) {
			if(s[j] == 'S')
				x += j;
			else if(s[j] == 'G')
				x -= j;
		}
		if(x < 0) {
			cout << "-1\n";
			return 0;
		}
		S.insert(x);
	}
	cout << S.size() << endl;
}