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

int n, m, w[MM], x[MM], y[MM], cnt[MM];
bool vis[MM], used[MM];
vector<pair<int, int>> adj[MM];
vector<int> out;
queue<int> q;

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		scan(w[i]);
	}
	for(int i = 1; i <= m; i++){
		scan(x[i], y[i]);
		cnt[x[i]]++, cnt[y[i]]++;
		adj[x[i]].emplace_back(y[i], i);
		adj[y[i]].emplace_back(x[i], i);
	}
	for(int i = 1; i <= n; i++){
		if(cnt[i] <= w[i]){
			vis[i] = 1;
			q.emplace(i);
		}
	}
	while(q.size()){
		int cur = q.front(); q.pop();
		for(auto e: adj[cur]){
			int u = e.first, id = e.second;
			if(used[id]) continue;
			used[id] = 1;
			cnt[u]--;
			out.emplace_back(id);
			
			if(!vis[u] and cnt[u] <= w[u]){
				q.emplace(u);
				vis[u] = 1;
			}
		}
	}
	if(out.size() < m){
		puts("DEAD");
		return 0;
	}
	puts("ALIVE");
	reverse(all(out));
	for(int i: out)
		printf("%d ", i);
}