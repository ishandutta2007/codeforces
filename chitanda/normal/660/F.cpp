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

typedef pair<ll, ll> myp;
int n, a[200100], top;
ll ans;
myp que[200100];

bool cmp(myp a, myp b) { return a.fi < b.fi || (a.fi == b.fi && a.se < b.se); }

bool check(myp x, myp y, myp z){
	return 1. * (z.fi - x.fi) * (x.se - y.se) >= 1. * (x.se - z.se) * (y.fi - x.fi);
}

ll f(myp a, ll x) { return a.fi * x + a.se; }

ll ask(ll x){
	int l = 1, r = top + 1;
	while(l + 1 < r){
		int m = (l + r) >> 1;
		if(f(que[m - 1], x) < f(que[m], x)) l = m;
		else r = m;
	}
	return f(que[l], x);
}

void work(int l, int r){
	if(l == r){
		ans = max(ans, (ll)a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	work(l, mid);
	work(mid + 1, r);
	
	vector<myp>q;
	ll sum1 = 0, sum2 = 0;
	for(int i = mid + 1; i <= r; i++){
		sum1 += (ll)a[i] * (i - mid);
		sum2 += a[i];
		q.pb(mkp(sum2, sum1));
	}
	sort(all(q), cmp);
	que[top = 0] = mkp(0, 0);
	for(auto v : q){
		while(top > 1 && check(que[top - 1], que[top], v)) top--;
		//if(top && v.fi == que[top].fi) top--;
		que[++top] = v;
	}
		
	sum1 = sum2 = 0;
	for(int i = mid; i >= l; i--){
		sum1 += a[i] + sum2;
		sum2 += a[i];
		ans = max(ans, ask(mid - i + 1) + sum1);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	work(1, n);
	cout << ans;
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