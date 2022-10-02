#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> V;
	vector<bool> no_op(n+1, false);// numeri presenti in V

	for (int i = 0; i < n; i++) {
		int K;
		cin >> K;

		if (K <= n and !no_op[K]) no_op[K] = true;
		else V.push_back(K);
	}

	sort(V.begin(), V.end());

	int posV = 0;
	
	for(int i = 1; i <= n; i++){
		if (!no_op[i]) {
			if (V[posV] < 2 * i + 1) {
				cout << "-1\n";
				return;
			}
			posV++;
		}
	}
	cout << V.size() << "\n";
}

 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
 
	while (t--) solve();
}