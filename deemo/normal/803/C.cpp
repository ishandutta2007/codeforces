#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, k;

bool check(ll x){
	ll rem = n/x;
	ll sm = 1ll*k*(k+1)/ 2ll;
	return sm <= rem;
}

void print(ll mx){
	ll rem = n/mx;
	for (int i = 1; i <= k; i++){
		if (i == k)
			cout << rem*mx << "\n";
		else
			cout << mx*i << " ";
		rem -= i;
	}
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if (k > (int)1e6){
		cout << "-1\n";
		return 0;
	}
	ll mx = -1;
	for (ll i = 1; i * i <= n; i++)
		if (n % i == 0){
			if (check(i))
				mx = max(mx, i);
			if (check(n/i))
				mx = max(mx, n/i);
		}
	if (~mx)
		print(mx);
	cout << "-1\n";
	return 0;
}