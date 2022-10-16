#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int MM = 1e5+5;

int t, n, m;
vector<int> adj[MM];
ll sz[MM];

ll dfs(int cur, int pre){
	sz[cur] = 1;
	for(int u: adj[cur])
		if(u != pre)
			sz[cur] += dfs(u, cur);
	return sz[cur];
}

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 0,a,b; i < n-1; i++){
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);			
		}
		dfs(1, 0);

		scan(m);
		vector<ll> f(m);
		for(int i = 0; i < m; i++){
			scan(f[i]);
		}
		while((int)f.size() < n-1)
			f.emplace_back(1);
		sort(all(f));
		while((int)f.size() > n-1){
			ll rm = f.back(); f.pop_back();
			f.back() = f.back()*rm%mod;
		}

		vector<ll> v(n-1);
		for(int i = 2; i <= n; i++){
			v[i-2] = (ll)sz[i]*(n-sz[i]);
		}
		sort(all(v));

		ll ans = 0;
		while(f.size()){
			ans = (ans + f.back()*(v.back()%mod))%mod;
			f.pop_back();
			v.pop_back();
		}
		print(ans);

		for(int i = 0; i <= n; i++){
			adj[i].clear();
			sz[i] = 0;
		}
	}
}