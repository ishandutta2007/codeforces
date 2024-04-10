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
const int MM = 2e5+5, LOG = 18;

int n, m, k, cnt, dep[MM], sp[LOG][MM];
vector<int> adj[MM];
bool vis[MM], on[MM];

void dfs(int cur, int pre){
	vis[cur] = on[cur] = 1;
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	for(int u: adj[cur]){
		if(vis[u] and on[u]){
			on[cur] = 0;
			break;
		}
	}
	cnt += on[cur];
	for(int u: adj[cur]){
		if(!vis[u]){
			dfs(u, cur);
		}
	}
}

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

int main(){
	scan(n, m, k);
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	memset(sp, -1, sizeof sp);
	dfs(1, 0);
	if(cnt >= (k+1)/2){
		print(1);
		for(int i = 0, l = 1; i < (k+1)/2; i++){
			while(!on[l])
				l++;
			printf("%d ", l);
			l++;
		}
		return 0;
	}
	cnt = 0;
	memset(vis, 0, sizeof vis);
	memset(on, 0, sizeof on);
	dfs(adj[1][0], 0);
	if(cnt >= (k+1)/2){
		print(1);
		for(int i = 0, l = 1; i < (k+1)/2; i++){
			while(!on[l])
				l++;
			printf("%d ", l);
			l++;
		}
		return 0;
	}

    for(int i = 1; i < LOG; i++){
        for(int j = 0; j <= n; j++){
            if(~sp[i-1][j])
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
        }
    }
    for(int i = 1; i <= n; i++){
    	for(int j: adj[i]){
    		int lca = getlca(i, j);
    		int len = 1+dep[i]+dep[j]-2*dep[lca];

    		if(len > 2 and len <= k){
    			int a = i, b = j;
    			if(dep[a] < dep[b])
    				swap(a, b);
    			//a is deeper
    			vector<int> v;
    			while(a != lca){
    				v.emplace_back(a);
    				a = sp[0][a];
    			}
    			v.emplace_back(lca);
    			reverse(all(v));
    			while(b != lca){
    				v.emplace_back(b);
    				b = sp[0][b];
    			}
    			
    			print(2);
    			print(v.size());
    			for(int u: v)
    				printf("%d ", u);
    			return 0;
    		}
    	}
    }
}