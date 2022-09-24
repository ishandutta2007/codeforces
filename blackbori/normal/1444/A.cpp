#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc()
{
	ll p, q, i, t, z, m;

	cin >> p >> q;
	if(p < q || p % q != 0){
		cout << p << "\n";
		return;
	}

	m = 0; t = q;
	for(i = 2; i * i <= t; i ++){
		if(t % i == 0){
			for(; t % i == 0; t /= i);
			for(z = p; ; z /= i){
				if(z % q != 0){
					m = max(m, z);
					break;
				}
				if(z % i != 0) break;
			}
		}
	}
	if(t != 1){
		i = t;
		for(z = p; ; z /= i){
			if(z % q != 0){
				m = max(m, z);
				break;
			}
			if(z % i != 0) break;
		}
	}

	cout << m << "\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	for(; t --; ) tc();

	return 0;
}