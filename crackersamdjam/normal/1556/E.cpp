#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 1e5+5;

int n, q;
int a[MM], b[MM];

struct segment_tree{
	#define lc rt<<1
	#define rc rt<<1|1
	#define nm ((nl+nr)/2)
	#define npm int nl = 0, int nr = n+2, int rt = 1
	#define lpm nl, nm, lc
	#define rpm nm+1, nr, rc
	
	struct node{
		ll sum, lhi, llo, rhi;
	} tree[MM*4];
	
	const node DEF = {0, INT_MIN/2, INT_MAX/2, INT_MIN/2};
	
	node merge(node l, node r){
		node x;
		x.sum = l.sum+r.sum;
		x.lhi = max(l.lhi, l.sum+r.lhi);
		x.llo = min(l.llo, l.sum+r.llo);
		x.rhi = max(l.rhi+r.sum, r.rhi);
		return x;
	}
	
	void pull(int rt){
		tree[rt] = merge(tree[lc], tree[rc]);
	}
	
	void build(npm){
		if(nl == nr){
			int v = b[nl]-a[nl];
			tree[rt] = {v, v, v, v};
			return;
		}
		build(lpm); build(rpm);
		pull(rt);
	}
	
	node query(int l, int r, npm){
		if(r < nl or nr < l) return DEF;
		if(l <= nl and nr <= r)
			return tree[rt];
		return merge(query(l, r, lpm), query(l, r, rpm));
	}

	#undef lc
	#undef rc
	#undef nm
	#undef npm
	#undef lpm
	#undef rpm
} ST;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>b[i];
	}
	ST.build();
	
	while(q--){
		int l, r;
		cin>>l>>r;
		auto res = ST.query(l, r);
		pr(res.sum, res.lhi, res.llo, res.rhi);
		if(res.sum or res.llo < 0 or res.rhi > 0){
			cout<<"-1\n";
		}
		else{
			cout<<res.lhi<<'\n';
		}
	}
}
/*
2 1
2 1
1 2
1 2

should be -1


*/