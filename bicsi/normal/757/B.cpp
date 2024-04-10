#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"

int Cnt[500000];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n, x;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> x;
		for(int d = 1; d * d <= x; ++d) {
			if(x % d == 0) {
				Cnt[d] += 1;
				if(d != x / d) 
					Cnt[x / d] += 1;
			}
		}
	}

	int ans = 1;
	for(int d = 2; d <= 100000; ++d)
		ans = max(ans, Cnt[d]);
	cout << ans << endl;
	return 0;
}