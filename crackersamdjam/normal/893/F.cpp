// https://codeforces.com/contest/893/problem/F
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
const int MM = 1e5+5, NN = 5e5+5;

struct cc{
	using T = int;
	static const T DEF = 1e9;
	T merge(const T &l, const T &r) const{ return min(l, r); }
};

template<class C> struct pseg{
#define nm ((nl+nr)>>1)
	using T = typename C::T;
	const T DEF = C::DEF;
	
	struct node{
		node *l, *r;
		T val;
		node(T vv){
			l = r = nullptr;
			val = vv;
		}
		node(node *_l, node *_r): l(_l), r(_r){ // merge two nodes
			val = C().merge(l->val, r->val);
		}
		~node(){
			if(l) delete l;
			if(r) delete r;
		}
	} *rt[NN];
	
	node *build(int nl, int nr){
		if(nl == nr) return new node(DEF);
		return new node(build(nl, nm), build(nm+1, nr));
	}
	node *update(node *cur,  int nl, int nr, int idx, T val){
		if(nl > idx || nr < idx) return cur;
		if(nl == nr) return new node(min(cur->val, val));
		return new node(update(cur->l, nl, nm, idx, val), update(cur->r, nm+1, nr, idx, val));
	}
	
	T query(node *cur, int nl, int nr, int l, int r){
		if(nl > r || nr < l) return DEF;
		else if(nl >= l && nr <= r) return cur->val;
		return C().merge(query(cur->l, nl, nm, l, r), query(cur->r, nm+1, nr, l, r));
	}
	
	void dout(node *cur, int nl, int nr){ // debug segtree
		// pr(nl, nr, cur->val);
		if(nl == nr) return;
		dout(cur->l, nl, nm); dout(cur->r, nm+1, nr);
	}
#undef nm
};

pseg<cc> ST;
int n, r, q, a[MM];
vector<int> adj[MM];
int dep[MM], maxd, in[MM], out[MM], t;
vector<int> v[MM];

void dfs(int cur, int pre){
	in[cur] = ++t;
	dep[cur] = dep[pre]+1;
	maxd = max(maxd, dep[cur]);
	v[dep[cur]].emplace_back(cur);
	for(int u: adj[cur])
		if(u != pre)
			dfs(u, cur);
	out[cur] = t;
}

int main(){
	scan(n, r);
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	for(int i = 0,b,c; i < n-1; i++){
		scan(b, c);
		adj[b].emplace_back(c);
		adj[c].emplace_back(b);
	}
	dfs(r, 0);
	ST.rt[0] = ST.build(1, n);
	for(int i = 1; i <= maxd; i++){
		ST.rt[i] = ST.rt[i-1];
		for(int j: v[i]){
			ST.rt[i] = ST.update(ST.rt[i], 1, n, in[j], a[j]);
		}
	}
	
	int last = 0;
	scan(q);
	while(q--){
		int x, y;
		scan(x, y);
		x = (x+last)%n+1, y = (y+last)%n;
		y = min(dep[x]+y, maxd);
		auto res = ST.query(ST.rt[y], 1, n, in[x], out[x]);
		print(last = res);
	}
}