#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll>	ans;

int main(){
	ll l, r, k;	cin >> l >> r >> k;
	if (l == 1)	ans.push_back(1);
	ll t = 1;
	while (r/ t >= k){
		t *= k;
		if (l <= t && t <= r)	ans.push_back(t);
	}

	if (ans.size() == 0)
		cout << -1 << "\n";
	else
		for (ll v:ans)
			cout << v << " ";
	cout << "\n";
	return	0;
}