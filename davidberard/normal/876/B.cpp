#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, K, M;
	cin >> N >> K >> M;
	vector<vector<int>> ofMod(M);
	int ans = -1;
	for(int i=0;i<N;++i) {
		int v;
		cin >> v;
		ofMod[v%M].push_back(v);
		if(ofMod[v%M].size() == K) {
			cout << "Yes" << endl;
			for(int vv : ofMod[v%M]) {
				cout << vv << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}