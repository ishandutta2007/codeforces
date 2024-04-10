#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int M = 2000;
int prime[M];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	fill(prime, prime+M, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i < M; ++i) {
		if(prime[i]) {
			for(int j = i*i; j < M; j += i) {
				prime[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	vector<pair<int,int>> ans;
	for(int i = 0; i < n; ++i) {
		ans.emplace_back(i, (i+1) % n);
	}

	int ctr = 0;
	while(!prime[n+ctr]) {
		if(ctr%2 == 0) {
			ans.emplace_back((ctr*2)%n, (ctr*2+2)%n);
		} else {
			ans.emplace_back(((ctr-1)*2+1)%n, ((ctr-1)*2+3)%n);
		}
		++ctr;
	}

	cout << ans.size() << '\n';
	for(auto x : ans)
		cout << x.first+1 << " " << x.second+1 << '\n';

}