#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int Z = 3e5;

ll m;

ll get(ll mid){
	ll ret = 0;
	for (ll k = 2; ret <= m && k <= Z; k++)
		ret += mid/ (k * k * k);
	return ret;
}

int main(){
	cin >> m;
	ll b = 0, e = 1e17, ret = 0;
	while (b <= e){
		ll mid = b+e>>1;
		if (get(mid) < m)
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	if (get(ret + 1) == m)
		cout << ret + 1 << "\n";
	else
		cout << "-1\n";
	return 0;
}