#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll LOG = 45;

ll n;
ll vec[MAXN];
ll tr[LOG * MAXN][2], sz;
ll maxi[LOG * MAXN];

void insert(ll x, ll ind){
	ll cur = 0;
	for (ll i = LOG - 1; i >= 0; i--){
		maxi[cur] = max(maxi[cur], ind);
		bool z = (x >> i) & 1;
		if (tr[cur][z] == 0)
			tr[cur][z] = ++sz;
		cur = tr[cur][z];
	}
	maxi[cur] = max(maxi[cur], ind);
}	

ll get(ll x, ll ind){
	ll cur = 0;
	ll ret = 0;
	for (ll i = LOG - 1; i >= 0; i--){
		bool z = (x >> i) & 1;
		if (z == 0){
			if (tr[cur][1] && maxi[tr[cur][1]] > ind){
				cur = tr[cur][1];
				ret ^= ll(1) << ll(i);
			}
			else	cur = tr[cur][0];
		}
		else{
			if (tr[cur][0] && maxi[tr[cur][0]] > ind)
				cur = tr[cur][0];
			else{
				cur = tr[cur][1];
				ret ^= ll(1) << ll(i);
			}
		}
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];

	ll x = 0, ans = 0;
	insert(x, n);
	for (ll i = n - 1; i >= 0; i--){
		x ^= vec[i];
		insert(x, i);
		ans = max(ans, x);
	}

	x = 0;
	for (ll i = 0; i < n; i++){
		x ^= vec[i];
		ans = max(ans, x ^ get(x, i));
	}	
	cout << ans << endl;
	return 0;
}