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
const int MM = 1e5+5;

int t, n, sz[MM];
vector<int> adj[MM], vec;

int getsz(int cur, int pre){
	bool b = 1;
	sz[cur] = 1;
	for(int u: adj[cur]){
		if(u != pre){
			sz[cur] += getsz(u, cur);
			if(sz[u] > n/2)
				b = 0;
		}
	}
	if(b && ((n - sz[cur]) <= n/2))
		vec.push_back(cur);
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
		getsz(1, 0);
		if(vec.size() == 1){
			print(1, adj[1][0]);
			print(1, adj[1][0]);
		}
		else{
			int a = vec[0], b = vec[1];
			for(int u: adj[a]){
				if(u != b){
					print(a, u);
					print(b, u);
					break;
				}
			}
		}
		vec.clear();
		for(int i = 0; i <= n; i++){
			adj[i].clear();
			sz[i] = 0;
		}
	}
}