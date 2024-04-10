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

const int maxn = 200100;
int n, k, b, c, M;
int t[maxn], w[maxn];
ll ans = 1LL << 60;
vector<int> v;

bool cmp(int x, int y) { return t[x] < t[y]; }

void get(int tag){
	ll cal = 0;
	priority_queue<ll> q;
	for(int i = 0, j = 1; i < (int)v.size(); i++){
		int x = v[i];
		if((x - M) % 5 != tag) continue;
		while(t[w[j]] <= x && j <= n){
			int l = (x - t[w[j]]) % 5;
			int p = (t[w[j]] + l - tag - M) / 5;
			ll cnt = (ll)p * b - (ll)l * c;
			q.push(-cnt), cal += cnt;
			if((int)q.size() > k) cal += q.top(), q.pop();
			j++;
		}
		if(q.size() == k) ans = min(ans, (ll)(x - M) / 5 * b * k - cal);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	cin >> n >> k >> b >> c; b = min(b, 5 * c);
	for(int i = 1; i <= n; i++){
		scanf("%d", t + i);
		for(int j = 0; j < 5; j++) v.pb(t[i] + j);
		w[i] = i;
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	sort(w + 1, w + n + 1, cmp);
	M = v[0];
	for(int i = 0; i < 5; i++) get(i);
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