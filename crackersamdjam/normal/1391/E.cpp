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
using pii = pair<int, int>;
const int MM = 5e5+5;

int t, n, m, dep[MM];
vector<int> adj[MM], v[MM];
vector<int> path;
bool done;

void dfs(int cur){
	path.emplace_back(cur);
	if(path.size()*2 >= n){
		puts("PATH");
		print(path.size());
		for(int i: path)
			printf("%d ", i);
		pc(10);
		done = 1;
		return;
	}
	v[dep[cur]].emplace_back(cur);
	for(int u: adj[cur]){
		if(!dep[u]){
			dep[u] = dep[cur]+1;
			dfs(u);
			if(done) return;
		}
	}
	path.pop_back();
}

int main(){
	scan(t);
	while(t--){	
		scan(n, m);
		while(m--){
			int a, b;
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		dep[1] = 1;
		dfs(1);
		if(!done){
			puts("PAIRING");
			int cnt = ((n+1)/2 +1)/2;
			print(cnt);
			for(int i = 1; i <= n; i++){
				while(v[i].size() > 1){
					if(!cnt) break;
					cnt--;
					int a = v[i].back(); v[i].pop_back();
					int b = v[i].back(); v[i].pop_back();
					print(a, b);
				}
			}
			assert(!cnt);
		}
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			v[i].clear();
			dep[i] = 0;
		}
		path.clear();
		done = 0;
	}
}