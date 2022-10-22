#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const ll MOD = 1e9 + 7;

struct Mat{
	ll n, m;
	vector<vector<ll>>	vec;
	Mat(ll x, ll y , ll val=0){
		n = x, m = y;
		vec.resize(n);
		for (ll i = 0 ; i < n ; i++)
			vec[i].resize(m);
		for (ll i = 0 ; i < n ; i++)
			for (ll j = 0 ; j < m ; j++){
				if (i == j)	vec[i][j] = val;
				else	vec[i][j] = 0;
			}
	}
};

Mat operator * (Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (ll i = 0; i < a.n; i++)
		for (ll j = 0; j < b.m; j++)
			for (ll k = 0; k < a.m; k++)
				ret.vec[i][j] = (ret.vec[i][j] + a.vec[i][k] * b.vec[k][j]) % MOD;
	return	ret;
}

Mat mpow(Mat a, ll b){
	Mat ans(a.n, a.m, 1);
	while (b){
		if (b & 1)
			ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return	ans;
}

ll n , m , k;

int main(){
	cin >> n >> m >> k;
	Mat g(m , 1);	
	for (ll i = 0 ; i < m ; i++)
		g.vec[i][0] = 1;
	
	Mat h(m, m);
	for (ll i = 0 ; i < k ; i++){
		string s;	cin >> s;	
		if (s[0] < 97)	s[0] -= 39;
		else	s[0] -= 97;
		if (s[1] < 97)	s[1] -= 39;
		else	s[1] -= 97;
		h.vec[s[0]][s[1]] = 1;
	}
	for (ll i = 0 ; i < m ; i++)
		for (ll j = 0 ; j < m ; j++){
			if (h.vec[i][j] == 0)	h.vec[i][j] = 1;
			else	h.vec[i][j] = 0;
		}	

	h = mpow(h, n - 1);
	g = h * g;
	ll ans = 0;
	for (ll i = 0 ; i < m ; i++)
		ans = (ans + g.vec[i][0]) % MOD;
	cout << ans << endl;
	return	0;
}