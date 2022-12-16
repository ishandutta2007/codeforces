#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;
	cout << "1 ";
	int b = N-1;
	vector<bool> used(N, 0);
	for(int i=1;i<=N;++i) {
		int v;
		cin >> v;
		used[v-1] = 1;
		while(b >= 0 && used[b]) {
			--b;
		}
		cout << 1 + i - (N-1-b) << " ";
	}
	cout << endl;
	return 0;
}