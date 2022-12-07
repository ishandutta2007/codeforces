//int!
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;

const int maxn = 100100;
int root, tot_size;
int size[maxn];
bool done[maxn];
vector<pair<int, int> >g[maxn];

int n, M;
map<int, int> mp;
int ten[maxn], ten_inv[maxn];
ll ans;

int power(int a, int b){
	int ans = 1;
	for(; b; b >>= 1, a = (ll)a * a % M)
		if(b & 1) ans = (ll)ans * a % M;
	return ans;
}										 

int getphi(int n){
	int phi = n, li = sqrt(n + 0.5);
	for(int i = 2; i <= li; ++i)
		if(n % i == 0){
			phi = phi / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	if(n > 1) phi = phi / n * (n - 1);
	return phi;
}

void getroot(int t, int fa){
	size[t] = 1;
	int tmax = 0;
	for(auto e : g[t]){
		int v = e.fi;
		if(v != fa && !done[v]){
			getroot(v, t);
			size[t] += size[v];
			tmax = max(tmax, size[v]);
		}
	}
	tmax = max(tmax, tot_size - size[t]);
	if(tmax <= tot_size / 2) root = t;
}

void dfs1(int s, int l, int t, int fa){
	ans += mp[(ll)(M - s) * ten_inv[l] % M];
	for(auto e : g[t]){
		int v = e.fi, w = e.se;
		if(!done[v] && v != fa)
			dfs1(((ll)s * 10 + w) % M, l + 1, v, t);
	}
}

void dfs2(int s, int l, int t, int fa){
	mp[s]++;
	for(auto e : g[t]){
		int v = e.fi, w = e.se;
		if(!done[v] && v != fa)
			dfs2((s + (ll)w * ten[l]) % M, l + 1, v, t);
	}
}

void work(int now){
	done[now] = 1;
	int m = g[now].size();

	mp.clear();
	mp[0] = 1;
	for(int i = 0; i < m; ++i){
		int v = g[now][i].fi, w = g[now][i].se % M;
		if(!done[v]){
			dfs1(w, 1, v, now);
			dfs2(w, 1, v, now);
		}
	}

	mp.clear();
	for(int i = m - 1; i >= 0; --i){
		int v = g[now][i].fi, w = g[now][i].se % M;
		if(!done[v]){
			dfs1(w, 1, v, now);
			dfs2(w, 1, v, now);
		}
	}
	ans += mp[0];

	getroot(root, 0); //get size
	for(auto e : g[now]){
		int v = e.fi;
		if(!done[v]){
			tot_size = size[v];
			getroot(v, 0);
			work(root);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &M);
	for(int i = 1; i < n; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u++, v++;
		g[u].pb(mkp(v, w));
		g[v].pb(mkp(u, w));
	}
	
	int inv = power(10, getphi(M) - 1);
	ten[0] = ten_inv[0] = 1;
	for(int i = 1; i <= n; ++i){
		ten[i] = (ll)ten[i - 1] * 10 % M;
		ten_inv[i] = (ll)ten_inv[i - 1] * inv % M;
	}
	
	tot_size = n;
	getroot(1, 0);
	work(root);

	printf("%lld\n", ans);
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