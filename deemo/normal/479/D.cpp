#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, l, x, y, vec[MAXN];
set<ll>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> x >> y;

	bool gals = 0, guys = 0;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		if (st.count(vec[i] - x))	gals = 1;
		if (st.count(vec[i] - y))	guys = 1;
		st.insert(vec[i]);
	}
	if (gals && guys){
		cout << 0 << "\n";
		return	0;
	}

	for (ll i = 0; i < n - 1; i++){
		bool gl = 0, gy = 0;
		ll p;
		if (!guys)	p = vec[i] + y;
		else	p = vec[i] + x;
		if (p > l)	continue;

		if (st.count(p - y))	gy = 1;
		if (st.count(p - x))	gl = 1;
		if (st.count(p + y))	gy = 1;
		if (st.count(p + x))	gl = 1;

		if ((gl || gals) && (guys || gy)){
			cout << 1 << "\n";
			cout << p << "\n";
			return	0;
		}
	}

	for (ll i = 1; i < n; i++){
		bool gl = 0, gy = 0;
		ll p;
		if (!guys)	p = vec[i] - y;
		else	p = vec[i] - x;
		if (p < 0)	continue;

		if (st.count(p - y))	gy = 1;
		if (st.count(p - x))	gl = 1;
		if (st.count(p + y))	gy = 1;
		if (st.count(p + x))	gl = 1;

		if ((gl || gals) && (guys || gy)){
			cout << 1 << "\n";
			cout << p << "\n";
			return	0;
		}
	}

	cout << 2 << "\n";
	cout << x << " " << y << "\n";
	return	0;
}