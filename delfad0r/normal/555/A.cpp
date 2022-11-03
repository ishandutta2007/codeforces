#include <bits/stdc++.h>

using namespace std;

int N, K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	int chain_l = 0;
	bool found_chain = false;
	int ans = 0;
	for(int k = 0; k < K; ++k) {
		int M;
		cin >> M;
		ans += M - 1;
		for(int i = 1; i <= M; ++i) {
			int x;
			cin >> x;
			if(!found_chain && x == i && chain_l + 1 == x)
				++chain_l;
		}
		if(chain_l > 0) found_chain = true;
	}
	cout << ans - 2 * chain_l + N + 1;
}