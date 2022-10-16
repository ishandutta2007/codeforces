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

int t, n, a[MM], b[MM], cnt[MM], vis[MM];
struct st{
	int u, c, id;
};
vector<st> adj[MM];

int main(){
	scan(t);
	while(t--){
		scan(n);
		bool no = 0;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			cnt[i] = 0;
			vis[i] = 0;
		}

		for(int i = 1; i <= n; i++){
			scan(a[i]);
			cnt[a[i]]++;
		}
		for(int i = 1; i <= n; i++){
			scan(b[i]);
			cnt[b[i]]++;
			adj[a[i]].push_back({b[i], 0, i});
			adj[b[i]].push_back({a[i], 1, i});
		}

		for(int i = 1; i <= n; i++){
			if(cnt[i] != 2){
				no = 1;
				break;
			}
		}
		if(no){
			print(-1);
			continue;
		}

		vector<int> ans;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				int cur = i, pre = 0;
				vector<int> va, vb;
				do{
					vis[cur] = 1;
					if(adj[cur][0].u == pre)
						swap(adj[cur][0], adj[cur][1]);
					if(adj[cur][0].c)
						vb.emplace_back(adj[cur][0].id);
					else
						va.emplace_back(adj[cur][0].id);
					pre = cur;
					cur = adj[cur][0].u;

				} while(cur != i);

				if(vb.size() < va.size())
					swap(va, vb);
				for(int i: va)
					ans.emplace_back(i);
			}
		}
		print(ans.size());
		for(int i: ans)
			printf("%d ", i);
		pc(10);
	}
}