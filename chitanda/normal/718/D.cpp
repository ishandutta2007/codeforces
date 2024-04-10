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

const int M1 = 1e9 + 7;
const int M2 = 1e9 + 8;
const int P = 239;
const int PP = 17;
const int maxn = 100100;

struct Hash{
	int cnt;
	int num1, num2;
	Hash(int cnt = 0, int num1 = 0, int num2 = 0): cnt(cnt), num1(num1), num2(num2) {}
	bool operator < (const Hash &a) const{
		return mkp(cnt, mkp(num1, num2)) < mkp(cnt, mkp(a.num1, a.num2));
	}
	Hash operator * (const int &P) const{
		return Hash(cnt, (ll)num1 * P % M1, (ll)num2 * P % M2);
	}
	Hash operator + (const Hash &a) const{
		return Hash(cnt + a.cnt, (num1 + a.num1) % M1, (num2 + a.num2) % M2);
	}
};
map<Hash, int> mp;
map<pair<int, int>, Hash> H;
int n, u, v, du[maxn], P1[maxn], P2[maxn];
vector<int> g[maxn];

Hash merge(Hash a, Hash b){
	int cnt = a.cnt + b.cnt;
	int h1 = ((ll)a.num1 * P1[b.cnt] % M1 + b.num1) % M1;
	int h2 = ((ll)a.num2 * P2[b.cnt] % M2 + b.num2) % M2;
	return Hash(cnt, h1, h2);
}

Hash dfs(int x, int fa){
	if(H.count(mkp(x, fa))) return H[mkp(x, fa)];
	vector<Hash> vec;
	for(auto v : g[x])
		if(v != fa)
			vec.pb(dfs(v, x));
	sort(all(vec));
	Hash has;
	for(auto v : vec)
		has = merge(has, v);
	has = has * PP + Hash(1, 2, 2);
	return H[mkp(x, fa)] = has;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		du[u]++, du[v]++;
		g[u].pb(v);
		g[v].pb(u);
	}
	P1[0] = P2[0] = 1;
	for(int i = 1; i <= n; ++i){
		P1[i] = P1[i - 1] * P % M1;
		P2[i] = P2[i - 1] * P % M2;
	}
	
	for(int i = 1; i <= n; ++i)
		if(du[i] <= 3) mp[dfs(i, 0)]++;

	printf("%d\n", mp.size());
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