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
const int MOD=1e9+9;//998244353;


struct mi {
	typedef decay<decltype(MOD)>::type T;
	T val; 
	explicit operator T() const { return val; }
	mi() { val = 0; }
	mi(ll v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.val == b.val; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.val < b.val; }
	friend ostream& operator<<(ostream& os, const mi& a) { 
		return os << a.val; }
   
	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi& m) { 
		if ((val += m.val) >= MOD) val -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((val -= m.val) < 0) val += MOD; 
		return *this; }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
 
	mi& operator*=(const mi& m) { 
		val = (ll)val*m.val%MOD; return *this; }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { 
		assert(!(a == 0)); return pow(a,MOD-2); }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
#define M (1<<19)
const mi s5=383008016;
mi rt[2];
mi co[2];
mi pw[2][M+2];
mi invr[2];




struct elem {//element of a monoid M
	mi sum;
	elem(mi _s=0) {sum=_s;}
	//friend ostream& operator<<(ostream& os, const elem& a) { os<<1;return os; }
};


struct oper {//element of set F of operations
	mi co[2];
	oper(mi _c0=0, mi _c1=0) {co[0]=_c0;co[1]=_c1;}
};

elem neutral_elem() {
	return elem();
}

oper neutral_oper() {
	return oper();
}

elem combine_elems(const elem& a,const elem& b) {
	return elem(a.sum+b.sum);
}

oper combine_opers(const oper& frst, const oper& sec) {
	//sec is the oper in parent node (higher), frst is child (deeper)
	return oper(frst.co[0]+sec.co[0], frst.co[1]+sec.co[1]);
}
 
elem d[2*M];
oper daux[2*M];

bool apply_oper_to_elem(const oper& f,elem& a,int l,int r) {
	//debug()<<imie(l)<<imie(r)<<imie(a.sum);
	FOR(j,2) if (f.co[j]!=0) a.sum+=f.co[j]*(pw[j][r+1]-pw[j][l])*invr[j];
	//debug()<<imie(a.sum);
	return true;
}

void recalc_node(int l,int r,int k,bool aux_only=0) {
	if (l<r && !aux_only) d[k]=combine_elems(d[2*k],d[2*k+1]);
	apply_oper_to_elem(daux[k],d[k],l,r);
	if (l==r) daux[k]=neutral_oper();
}
		
	
bool apply_if_possible(int l,int r,int k,const oper& f) {
	if (apply_oper_to_elem(f,d[k],l,r)) {
		daux[k]=f;
		if (l==r) daux[k]=neutral_oper();
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
	if (daux[k].co[0]==0 && daux[k].co[1]==0) return;
	assert(l<r);
	combine_aux_from_parent(l,(l+r)/2,l,r,k*2);
	combine_aux_from_parent((l+r)/2+1,r,l,r,k*2+1);
	daux[k]=neutral_oper();
}
	
	

void modify(int li,int ri,const oper& f,int l=0,int r=M-1,int k=1) {
	if (r<li || ri<l) return;
	if (l<r) pushdown_aux(l,r,k);
	if (li<=l && r<=ri && apply_if_possible(l,r,k,f)) return;
	//the operations in recursive calls might be different ->f_left, f_right
	modify(li,ri,f,l,(l+r)/2,k*2);
	modify(li,ri,f,(l+r)/2+1, r, k*2+1);
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
	rt[0]=(s5+1)/mi(2);
	rt[1]=(1-s5)/mi(2);
	co[1]=(1-rt[0])/(rt[1]-rt[0]);
	co[0]=1-co[1];
	FOR(j,2) {
		invr[j]=1/(rt[j]-1);
		pw[j][0]=1;
		REP(i,1,M) pw[j][i]=pw[j][i-1]*rt[j];
	}
	int n,q;cin>>n>>q;
	FOR(i,n) {
		int x;cin>>x;
		d[i+M]=elem(x);
	}
	REPD(i,M-1,1) d[i]=combine_elems(d[2*i],d[2*i+1]);
	mi powM[2]={pow(rt[0],MOD-1-M), pow(rt[1],MOD-1-M)};
	while(q--) {
		int tp,a,b;
		cin>>tp>>a>>b;a--;b--;
		//debug()<<imie(d[1].sum);
		if (tp==1) {
			oper op=oper(co[0]*powM[0]*pw[0][M-a],co[1]*powM[1]*pw[1][M-a]);
			//debug()<<imie(op.co[0])<<imie(op.co[1])<<imie(op.co[0]+op.co[1]);
			modify(a,b,op);
		}
		if (tp==2) {
			cout<<query(a,b).sum<<"\n";
		}
	}



    return 0;
}