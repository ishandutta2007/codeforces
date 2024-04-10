#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 6e5+5;

using pii = pair<int, int>;
using T = pii;
using L = pii;

struct Segtree{
	#define lc rt<<1
	#define rc rt<<1|1
	#define nm ((nl+nr)/2)
	#define npm int nl = 0, int nr = MM, int rt = 1
	#define lpm nl, nm, lc
	#define rpm nm+1, nr, rc
	
	struct node{
		T val; L lp;
		// int sz;
		inline void apply(L v){
			val = max(val, v);
			lp = max(lp, v);
		}
	} tree[MM*4];
	
	const T DEF = {0, 0}; const L DEFL = {0, 0};
	
	T merge(T va, T vb){
		return max(va, vb);
	}
	
	void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	
	void push(int rt, int nl, int nr){
		// node with lazy val means yet to push to children (but updated itself)
		if(nl == nr or tree[rt].lp == DEFL) return;
		L &x = tree[rt].lp; tree[lc].apply(x); tree[rc].apply(x); x = DEFL;
	}
	
	void build(npm){
		tree[rt].val = DEF;
		tree[rt].lp = DEFL;
		// tree[rt].sz = nr-nl+1;
		if(nl == nr) return;
		build(lpm); build(rpm);
	}
	
	void update(int l, int r, L x, npm){
		if(r < nl or nr < l) return;
		if(l <= nl and nr <= r){
			tree[rt].apply(x);
			return;
		}
		push(rt, nl, nr);
		update(l, r, x, lpm); update(l, r, x, rpm);
		pull(rt);
	}
	
	T query(int l, int r, npm){
		if(r < nl or nr < l) return DEF;
		if(l <= nl and nr <= r)
			return tree[rt].val;
		push(rt, nl, nr);
		return merge(query(l, r, lpm), query(l, r, rpm));
	}

	#undef lc
	#undef rc
	#undef nm
	#undef npm
	#undef lpm
	#undef rpm
} ST;

int n, m;
vector<pair<int, int>> v[MM];
map<int, int> mp;

pii dp[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	while(m--){
		int i, l, r;
		cin>>i>>l>>r;
		v[i].emplace_back(l, r);
		mp[l] = mp[r] = 0;
	}
	{
		int x = 0;
		for(auto &i: mp)
			i.second = ++x;
	}

	pii ans = {0, 0};

	for(int i = 1; i <= n; i++){
		for(auto [l, r]: v[i]){
			l = mp[l], r = mp[r];
			dp[i] = max(dp[i], ST.query(l, r));
		}
		pii val = {dp[i].first+1, i};
		ans = max(ans, val);
		for(auto [l, r]: v[i]){
			l = mp[l], r = mp[r];
			ST.update(l, r, val);
		}
	}
	set<int> keep;
	while(ans.second){
		keep.insert(ans.second);
		ans = dp[ans.second];
	}
	cout<<n-size(keep)<<'\n';
	for(int i = 1; i <= n; i++){
		if(!keep.count(i)){
			cout<<i<<' ';
		}
	}
}