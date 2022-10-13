#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n;
	cin >> n;

	vector<int> V(n);
	for(int i = 0; i < n; ++i) {
		cin >> V[i];
	}

	long long ans = 0;
	sort(V.begin(), V.end());
	for(int i = 0; i < n; ++i) {
		ans += V.back() - V[i];
	}
	cout << ans << endl;

	return 0;
}