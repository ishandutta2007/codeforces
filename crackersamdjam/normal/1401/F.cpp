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

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

using namespace std;
using ll = long long;
const int MM = (1<<18)+5;

struct node{
	ll sum;
} tree[MM<<1];

int n, q, a[MM];
bool lp[20];

void build(int nl, int nr, int rt){
	if(nl == nr){
		tree[rt].sum = a[nl];
		return;
	}
	build(nl, nm, lc); build(nm+1, nr, rc); tree[rt].sum = tree[lc].sum + tree[rc].sum;
}

void update(int l, int val, int nl, int nr, int rt){
	if(nl == nr){
		tree[rt].sum = val;
		return;
	}
	int h = nm-nl+1;
	if(l <= nm) !lp[__lg(nr-nl+1)] ? update(l, val, nl, nm, lc) : update(l+h, val, nm+1, nr, rc);
	else !lp[__lg(nr-nl+1)] ? update(l, val, nm+1, nr, rc) : update(l-h, val, nl, nm, lc);

	tree[rt].sum = tree[lc].sum + tree[rc].sum;
}

ll query(int l, int r, int nl, int nr, int rt){
	if(r < nl || l > nr) return 0;
	if(l <= nl && r >= nr) return tree[rt].sum;

	int h = nm-nl+1;
	ll ret = 0;
	if(l <= nm){
		ret += !lp[__lg(nr-nl+1)] ? query(l, min(r, nm), nl, nm, lc) : query(l+h, min(r, nm)+h, nm+1, nr, rc);
	}
	if(r > nm){
		ret += !lp[__lg(nr-nl+1)] ? query(max(l, nm+1), r, nm+1, nr, rc) : query(max(l, nm+1)-h, r-h, nl, nm, lc);
	}
	return ret;
}

int main(){
	scan(n, q);
	n = 1<<n;
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	build(1, n, 1);
	while(q--){

		int op, b, c;
		scan(op, b);
		if(op == 1){
			scan(c);
			update(b, c, 1, n, 1);
		}
		if(op == 2){
			for(int i = 0; i <= b; i++)
				lp[i] ^= 1;
		}
		if(op == 3){
			lp[b+1] ^= 1;
		}
		if(op == 4){
			scan(c);
			print(query(b, c, 1, n, 1));
		}
		// for(int i = 1; i <= n; i++)
		// 	cout<<query(i, i, 1, n, 1)<<' ';;
		// cout<<endl;
	}
}