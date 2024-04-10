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

int t, n, k, ans, cnt[MM], cnt2[MM], two[MM];
vector<int> adj[MM];

void dfs(int cur, int pre){
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dfs(u, cur);
		if(cnt[u]+cnt2[u]){
			cnt[cur]++;
			two[cur] = u;
		}
		else{
			//can be removed
			cnt2[cur]++;
		}
	}
	while(cnt2[cur] >= k){
		cnt2[cur] -= k;
		ans++;
		// printf("add %d\n", cur);
	}
	// print(cur, cnt[cur], cnt2[cur]);
}

int main(){
	scan(t);
	while(t--){
		scan(n, k);
		for(int i = 0,a,b; i < n-1; i++){
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}

		if(k == 1){
			print(n-1);
			goto out;
		}
		{
		dfs(1, 0);
		// print(ans);
		//now choose which one to go down... dp
		int cur = 1;
		while(cnt[cur] == 1 and !cnt2[cur] and two[cur] and cnt2[two[cur]]+1 == k){
			ans++;
			cnt2[two[cur]] -= k-1;
			cur = two[cur];
			// print(cur, cnt[cur], cnt2[cur], cnt2[two[cur]]+1);
		}
		print(ans);

		}
		out:;
		ans = 0;
		for(int i = 0; i <= n; i++){
			cnt[i] = cnt2[i] = two[i] = 0;
			adj[i].clear();
		}
	}	
}