#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int n, m, dfn[MM], low[MM], t, path[MM], ptr, id[MM], sz[MM];
bool ins[MM];
vector<int> adj[MM];
set<int> adj2[MM];

void dfs(int cur){
	ins[cur] = 1;
	path[++ptr] = cur;
	dfn[cur] = low[cur] = ++t;

	for(int u: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	if(dfn[cur] == low[cur]){
		int u = 0;
		do{
			u = path[ptr--];
			ins[u] = 0;
			id[u] = cur;
			sz[cur]++;
		} while(u != cur);
	}
}
int ans, par[MM], sz2[MM];
int cyc[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int va[MM], vb[MM];

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		par[i] = i;
		sz2[i] = 1;
	}
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		va[i] = a, vb[i] = b;
		a = find(a), b = find(b);
		if(a != b){
			par[a] = b;
			sz2[a] += sz2[b];
		}
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i])
			dfs(i);
	}
	for(int i = 0,a,b; i < m; i++){
		a = id[va[i]], b = id[vb[i]];
		assert(a and b);
		if(a != b){
			adj2[a].insert(b);
		}
	}

	for(int i = 1; i <= n; i++){
		// print(i, id[i], sz[i]);
		ans += sz2[i]-1;
		if(sz[i] > 1){
			if(!cyc[find(i)]){
				ans++;
				cyc[find(i)] = 1;
			}
		}
	}

	print(ans);
}