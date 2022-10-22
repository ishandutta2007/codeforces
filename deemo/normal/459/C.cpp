#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 5;

ll n, k, d, sz;
ll ans[MAXN][MAXN], sec[MAXN], t;

void gen(ll rem){
	if (rem == 0){
		for (ll i = 0; i < d; i++)
			ans[i][sz] = sec[i];
		sz++;
		return;
	}

	for (ll i = 1; i <= k; i++){
		if (sz == n)	return;
		sec[t++] = i;
		gen(rem - 1);
		t--;
	}
}

int main(){
	cin >> n >> k >> d;
	bool fl = 0;
	ll z = k;
	for (ll i = 0; i < d; i++){
		if (z >= n)	fl = 1;
		z *= k;
	}
	if (fl == 0){
		cout << -1 << endl;
		return	0;
	}
	gen(d);

	for (ll i = 0; i < d; i++){
		for (ll j = 0; j < n; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	return	0;
}