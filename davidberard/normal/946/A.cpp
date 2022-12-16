#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int sm = 0;
	int N;
	cin >> N;
	int v;
	for(int i=0;i<N;++i) {
		cin >> v;
		sm += abs(v);
	}
	cout << sm;

	return 0;
}