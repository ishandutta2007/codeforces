#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


vector<ll> L;
ll l,r,x,y;

bool ml(ll a, ll b) {
	return (a*b)/b == a;
}

vector<ll> X,Y;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> x >> y >> l >> r;
	ll a = 1;
	while(1) {
		if(a > r) break;
		X.push_back(a);
		if(!ml(a,x)) break;
		a *= x;
	}

	a = 1;
	while(1) {
		if(a > r) break;
		Y.push_back(a);
		if(!ml(a,y)) break;
		a *= y;
	}
	for(int i = 0; i < X.size(); ++i) {
		for(int j = 0; j < Y.size(); ++j) {
			ll a = X[i]+Y[j];
			if(a > X[i] && a > Y[j]) {
				if(l <= a && a <= r)
					L.push_back(a);
			}
		}
	}
	L.push_back(l-1);
	L.push_back(r+1);
	sort(L.begin(),L.end());
	ll ans = 0;
	for(int i = 1; i < L.size(); ++i) {
		ans = max(ans,L[i] - L[i-1]-1);
	}
	cout << ans << "\n";
	return 0;
}