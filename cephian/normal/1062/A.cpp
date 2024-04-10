#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n+2);
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	v[n+1] = 1e3+1;
	int best = 0, cur = 0;
	for(int i = 1; i <= n; ++i) {
		if(v[i-1]+1 == v[i] && v[i]+1 == v[i+1]) {
			++cur;
			best = max(best, cur);
		} else 
			cur = 0;
	}
	cout << best << "\n";

}