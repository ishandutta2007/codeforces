#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> okay(M), me(N);
	for(auto& ii :me  ) cin >> ii;
	for(auto& ii :okay) cin >> ii;
	for(int i=0;i<me.size();++i) {
		for(int j=0;j<okay.size();++j) {
			if(okay[j] == me[i]) {
				cout << me[i] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}