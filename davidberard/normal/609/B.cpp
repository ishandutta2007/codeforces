#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> amt(M, 0);
	int v;
	for(int i=0;i<N;++i) {
		cin >> v;
		amt[--v]++;
	}
	ll tot = 0;
	for(int i=0;i<M-1;++i) {
		for(int j=i+1;j<M;++j) {
			tot += ((ll)amt[i])*amt[j];
		}
	}
	cout << tot << endl;

	return 0;
}