#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

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

ll n , sx , sy , dx, dy, t;

Mat operator * (Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (ll i = 0; i < a.n; i++)
		for (ll j = 0; j < b.m; j++)
			for (ll k = 0; k < a.m; k++){
				ret.vec[i][j] = (ret.vec[i][j] + a.vec[i][k] * b.vec[k][j] + n * int(1e5)) % n;
			//	if (ret.vec[i][j] == 0)	ret.vec[i][j] = n;
			}
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

int main(){
	cin >> n >> sx >> sy >> dx >> dy >> t;
	Mat g(6 , 1);	
	g.vec = {{sx}, {sy}, {dx}, {dy}, {0}, {1}};
	
	Mat h(6, 6);
	h.vec = {{2, 1, 1, 0, 1, 0},
			 {1, 2, 0, 1, 1, 0},
			 {1, 1, 1, 0, 1, 0},
			 {1, 1, 0, 1, 1, 0},
			 {0, 0, 0, 0, 1, 1},
			 {0, 0, 0, 0, 0, 1}};
	h = mpow(h, t);
	g = h * g;
	if (g.vec[0][0] == 0)	g.vec[0][0] = n;
	if (g.vec[1][0] == 0)	g.vec[1][0] = n;
	cout << g.vec[0][0] << " " << g.vec[1][0] << endl;
	return	0;
}