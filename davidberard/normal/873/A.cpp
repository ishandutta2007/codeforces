#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N, K, X;
	cin >> N >> K >> X ;
	vector<int> vec = vector<int>(N);
	for(int i=0;i<N;++i) {
		cin >> vec[i];
	}
	for(int i=0;i<N && i < K && vec[N-i-1] > X;++i) {
		vec[N-i-1] = X;
	}
	ll amt = 0;
	for(int i=0;i<N;++i) {
		amt += vec[i];
	}
	cout << amt << endl;


	return 0;
}