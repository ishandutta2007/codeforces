//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
#define M 1000003

ll n, k;

ll mul(ll a, ll b, ll m){
	a %= m, b %= m;
	return a * b % m;
}

ll _pow(ll a, ll b, ll m){
	a %= m;
	ll ans = 1;
	for(; b; b >>= 1, a = a * a % m)
		if(b & 1) ans = ans * a % m;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> k;

	if(n < 60 && k > (1LL << n)){
		cout << "1 1";
		return 0;
	}
	
	ll p, q;

	ll cnt = 0;
	for(int i = 1; (1LL << i) < k; ++i)
		cnt += (k - 1) / (1LL << i);

	q = _pow(2, (mul(n, k - 1, M - 1) - cnt % (M - 1) + (M - 1)) % (M - 1), M);

	if(k >= M) p = 0;
	else{
		p = 1;
		ll tmp = _pow(2, n, M);
		for(int i = 1; i < k; ++i)
			p = p * ((tmp - i + M) % M) % M;
		p = p * _pow(_pow(2, cnt % (M - 1), M), M - 2, M) % M;
	}

	p = (q - p + M) % M;
	cout << p << ' ' << q;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/