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
const int MM = 2e5+5;

vector<int> adj[MM];
int t, n, m, dp[MM];
bool vis[MM];
vector<int> out;

int dfs(int cur){
	if(vis[cur])
		return dp[cur];
	vis[cur] = 1;
	int &l = dp[cur] = 1;
	
	for(int u: adj[cur]){
		l = max(l, dfs(u)+1);
	}
	
	if(l >= 3){
		out.emplace_back(cur);
		l = 0;
	}
	return l;
}

int main(){
	scan(t);
	while(t--){
		priority_queue<pii> q;
		out.clear();
		for(int i = 1; i <= n; i++){
			vis[i] = 0;
			adj[i].clear();
		}
		scan(n, m);
		while(m--){
			int a, b;
			scan(a, b);
			adj[b].emplace_back(a);
		}
		for(int i = 1; i <= n; i++){
			dfs(i);
		}
		print(out.size());
		for(int i: out)
			printf("%d ", i);
		pc(10);
	}
}
/*
3
5 7
4 5
3 5
1 3
1 5
2 3
3 4
2 4

5 7
1 5
4 5
3 5
1 3
3 4
2 4
2 3

1
5 7
2 3
1 4
2 4
3 4
3 5
1 3
4 5

 */