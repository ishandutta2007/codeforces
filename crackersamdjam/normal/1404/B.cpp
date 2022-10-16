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

int t, n, sa, sb, da, db;
vector<int> adj[MM];
int dis[MM], dis2[MM], ed;

void dfs(int cur, int pre){
	dis[cur] = dis[pre]+1;
	if(dis[cur] > dis[ed])
		ed = cur;
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
}

void dfs2(int cur, int pre){
	dis2[cur] = dis2[pre]+1;
	if(dis2[cur] > dis2[ed])
		ed = cur;
	for(int u: adj[cur]){
		if(u != pre)
			dfs2(u, cur);
	}
}

int main(){
	scan(t);
	while(t--){
		scan(n, sa, sb, da, db);
		for(int i = 0,a,b; i < n-1; i++){
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		dis[0] = -1;
		ed = 0; dfs(sa, 0);
		if(dis[sb] <= da){
			puts("Alice");
			goto out;
		}
		else{
			int l = ed;
			ed = 0; dfs(l, 0);
			int r = ed;
			int dia = dis[r];

			// dis2[0] = -1;
			// ed = 0; dfs2(sb, 0);
			// int mx = dis2[ed];

			if(db >= 2*da+1 and dia >= 2*da+1){
				puts("Bob");
			}
			else{
				puts("Alice");
			}
		}

		out:;
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
	}
}