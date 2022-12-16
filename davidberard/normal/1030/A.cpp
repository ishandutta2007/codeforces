#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	int sum = 0;
	for(int i=0;i<N;++i) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << (sum ? "HARD" : "EASY") << endl;
	return 0;
}