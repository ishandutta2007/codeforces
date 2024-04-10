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
const int MM = 1005;

int t, n, dep[MM], maxd, rt, ans, id;
vector<int> adj[MM], ask, v[MM];
pair<int, int> res[MM];

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	maxd = max(maxd, dep[cur]);
	v[dep[cur]].emplace_back(cur);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
}

pair<int, int> askq(){
	assert(ask.size());
	cout<<"? "<<ask.size();
	for(int i: ask)
		cout<<' '<<i;
	cout<<endl;
	ask.clear();
	int a, b;
	cin>>a>>b;
	return {a, b};
}

void dfs2(int cur, int pre, int k){
	if(k == ans){
		ask.emplace_back(cur);
	}
	for(int u: adj[cur]){
		if(u != pre)
			dfs2(u, cur, k+1);
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		maxd = 0;
		memset(res, 0, sizeof res);
		for(int i = 0; i < MM; i++){
			adj[i].clear();
			v[i].clear();
		}
		for(int i = 0,a,b; i < n-1; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		for(int i = 1; i <= n; i++)
			ask.emplace_back(i);
		tie(rt, ans) = askq();
		
		dep[0] = -1;
		dfs(rt, 0);
		
		int l = (ans+1)/2, m, r = maxd;
		while(l <= r){
			m = (l+r)/2;
			ask = v[m];
			res[m] = askq();
			if(res[m].second != ans)
				r = m-1;
			else
				l = m+1;
		}
		if(!res[r].first){
			ask = v[r];
			res[r] = askq();
		}
		id = res[r].first;
		dfs2(id, 0, 0);
		
		int s = askq().first;
		
		cout<<"! "<<id<<' '<<s<<endl;
		
		string ret;
		cin>>ret;
		assert(ret == "Correct");
	}
}