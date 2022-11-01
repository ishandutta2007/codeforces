//#pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define un(x) x.erase(unique(ALL(x)),x.end())
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int MOD=1e9+7;//998244353;

#define INF (1LL<<60)
#define M (1<<18)

struct elem {//element of a monoid M
	ll x;
	elem(ll _x=INF){x=_x;}
};


struct oper {//element of set F of operations
	ll v;
	oper(ll _v=0){v=_v;}
};

elem neutral_elem() {
	return elem();
}

oper neutral_oper() {
	return oper();
}

elem combine_elems(elem a,elem b) {
	return elem(min(a.x,b.x));
}

oper combine_opers(oper frst, oper sec) {
	return oper(frst.v+sec.v);
}
 
elem d[2*M];
oper daux[2*M];

elem apply_oper_to_elem(oper f,elem a) {
	return elem(a.x+f.v);
}

void recalc_node(int l,int r,int k,bool aux_only=0) {
	if (l<r && !aux_only) d[k]=combine_elems(d[2*k],d[2*k+1]);
	d[k]=apply_oper_to_elem(daux[k],d[k]);
	if (l==r) daux[k]=neutral_oper();
}
	
	
bool apply_if_possible(int l,int r,int k,oper op) {
	if (1) {
		daux[k]=op;
		recalc_node(l,r,k,1);
		return true;
	} 
	return false;
}
	

void combine_aux_from_parent(int l,int r,int pl, int pr,int k) {
	int pk=k/2;
	daux[k]=combine_opers(daux[k], daux[pk]);
	recalc_node(l,r,k);
}

void pushdown_aux(int l,int r,int k) {
	assert(l<r);
	combine_aux_from_parent(l,(l+r)/2,l,r,k*2);
	combine_aux_from_parent((l+r)/2+1,r,l,r,k*2+1);
	daux[k]=neutral_oper();
}
	

void modify(int li,int ri,oper op,int l=0,int r=M-1,int k=1) {
	if (r<li || ri<l) return;
	if (l<r) pushdown_aux(l,r,k);
	if (li<=l && r<=ri && apply_if_possible(l,r,k,op)) return;
	//the operations in recursive calls might be different ->op_left, op_right
	modify(li,ri,op,l,(l+r)/2,k*2);
	modify(li,ri,op,(l+r)/2+1, r, k*2+1);
	recalc_node(l,r,k);
}

void set_elem(int pos,elem a,int l=0,int r=M-1,int k=1) {
	if (l<r) pushdown_aux(l,r,k);
	else { //l==r==pos
		d[k]=a;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) set_elem(pos,a,l,mid,k*2);
	else set_elem(pos,a,mid+1,r,k*2+1);
	recalc_node(l,r,k);
}


elem query(int li,int ri,int l=0,int r=M-1,int k=1) {
	if (r<li || ri<l) return neutral_elem();
	if (li<=l && r<=ri) return d[k];
	pushdown_aux(l,r,k);
	return combine_elems(query(li,ri,l,(l+r)/2,k*2),query(li,ri,(l+r)/2+1,r,k*2+1));
}

	
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	int n;cin>>n;
	FOR(i,n) {
		int x;cin>>x;
		elem e(x);
		set_elem(i,e);
	}
	int q;cin>>q;
	string s;
	getline(cin,s);
	FOR(i,q) {
		getline(cin,s);
		stringstream ss(s);
		vi v;
		int x;
		while(ss>>x) {v.pb(x);}
		if (SZ(v)==3) {
			int L=v[0],R=v[1],val=v[2];
			if (L<=R) modify(L,R,oper(val));
			else {
				int L1=L,R1=n-1;
				int L2=0,R2=R;
				modify(L1,R1,val);
				modify(L2,R2,val);
			}
		} else {
			int L=v[0],R=v[1];
			if (L<=R) cout<<query(L,R).x<<"\n";
			else {
				int L1=L,R1=n-1;
				int L2=0,R2=R;
				cout<<min(query(L1,R1).x, query(L2,R2).x)<<"\n";
			}
			
		}
	}
		



    return 0;
}