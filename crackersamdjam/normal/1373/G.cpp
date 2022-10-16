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
typedef int T;
const int MM = 4e5+5;

int n, k, m;
set<pair<int, int>> in;
multiset<int> st;

struct node{
    T val, lp;
    void apply(T v){
        val += v;
        lp += v;
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
#define LS 0
#define RS MM-1
    node tree[MM*4];
    T DEF = 0;
    //default value
    
    T merge(T va, T vb){
        return max(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        T &val = tree[rt].lp;
        if(nl != nr){
            tree[lc].apply(val);
            tree[rc].apply(val);
        }
        val = DEF;
    }
	
	void build(int l, int r, int rt){
		int nl = l, nr = r;
		if(l == r){
			tree[rt].val = l;
			tree[rt].lp = 0;
			return;
		}
		build(l, nm, lc);
		build(nm+1, r, rc);
		push_up(rt);
	}
	
	void build(){
    	build(LS, RS, 1);
	}
    
    void update(int l, int r, T val, int nl, int nr, int rt){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            tree[rt].apply(val);
            return;
        }
        push_down(rt, nl, nr);
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
	void update(int l, int r, T val){
			update(l, r, val, LS, RS, 1);
    }
		
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return DEF;
		if(l <= nl && r >= nr)
			return tree[rt].val;
		push_down(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
	
	T query(int l, int r){
		return query(l, r, LS, RS, 1);
	}
#undef lc
#undef rc
#undef nm
} ST;

int main(){
	scan(n, k, m);
	ST.build();
	while(m--){
		int x, y;
		scan(x, y);
		if(in.count({x, y})){
			in.erase({x, y});
			y += abs(x-k);
			st.erase(st.lower_bound(y));
			ST.update(1, y, -1);
		}
		else{
			in.insert({x, y});
			y += abs(x-k);
			st.insert(y);
			ST.update(1, y, 1);
		}
		int mx = st.size() ? *--st.end() : 1;
		print(max(0, ST.query(1, mx)-1-n));
	}
}