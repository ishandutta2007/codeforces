#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1<<18;
int a[N];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	std::priority_queue<int, vector<int>, greater<int>> Q;
	ll ans = 0;
	for(int j = n-1; ; --j) {
		if(a[j] == -1) break;
		Q.push(a[j]);
		//cout << "pushed " << a[j] << endl;
		if(((j+1)&-(j+1)) == (j+1)) {
			ans += Q.top();
			//cout << "took " << Q.top() << endl;
			Q.pop();
		}
	}
	cout << ans << '\n';
}