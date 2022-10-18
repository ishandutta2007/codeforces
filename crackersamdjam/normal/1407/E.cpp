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
const int MM = 5e5+5;

int n, m, dis[MM][2];
vector<pair<int, int>> adj[MM];
queue<pair<int, int>> q;

int main(){
	scan(n, m);
	while(m--){
		int a, b, c;
		scan(a, b, c);
		// adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	memset(dis, 0x3f, sizeof dis);
	dis[n][0] = 0;
	dis[n][1] = 0;
	q.emplace(n, 0);
	q.emplace(n, 1);
	while(q.size()){
		int cur, f;
		tie(cur, f) = q.front(); q.pop();
		// if(dis[cur][!f] == 0x3f3f3f3f)
			// continue;
		// print(dis[cur][f], dis[cur][!f]);
		if(dis[cur][f] < dis[cur][!f])
			continue;
		for(auto [u, w]: adj[cur]){
			if(dis[cur][f]+1 < dis[u][w]){
				dis[u][w] = dis[cur][f]+1;
				q.emplace(u, w);
			}
		}
	}
	int ans = max(dis[1][0], dis[1][1]);
	print(ans == 0x3f3f3f3f ? -1: ans);
	for(int i = 1; i <= n; i++){
		pc((dis[i][0] < dis[i][1]) + '0');
	}
	pc(10);
}