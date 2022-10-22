#include <bits/stdc++.h>
using namespace std;
template <int MOD_> struct modnum{
	static constexpr int MOD=MOD_;
	static_assert(MOD_>0,"MOD must be positive");
private:
	using ll = long long;
	int v;
	static int minv(int a,int m){
		a%=m;
		assert(a);
		return a==1?1:int(m-ll(minv(m,a))*ll(m)/a);
	}
public:
	modnum():v(0) {}
	modnum(ll v_):v(int(v_ % MOD)){if (v<0) v+=MOD;}
	explicit operator int() const {return v;}
	friend std::ostream& operator << (std::ostream& out,const modnum& n){ return out << int(n);}
	friend std::istream& operator >> (std::istream& in,modnum& n){ ll v_; in >> v_; n = modnum(v_); return in;}
	friend bool operator == (const modnum& a,const modnum& b){ return a.v == b.v;}
	friend bool operator != (const modnum& a,const modnum& b){ return a.v != b.v;}
	modnum inv() const {
		modnum res;
		res.v=minv(v,MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }
 
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}
 
	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}
 
	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<998244353>;
num A;
num B;
num C;
int n;
string s;
struct info{
	int lc,rc;
	num x,y;
};
info combine(info a,info b){
	if(a.lc==-1 && b.lc==-1){
		return {-1,a.rc^b.rc,0,0};
	}else if(a.lc==-1){
		return {a.rc^b.lc,b.rc,b.x,b.y};
	}else if(b.lc==-1){
		return {a.lc,a.rc^b.rc,a.x,a.y};
	}else{
		return {a.lc,b.rc,a.x+a.y*(((a.rc^b.lc)?B:C)+A*b.x),a.y*b.y*A};
	}
}
struct node{
	node *l,*r;
	info a;
};
node* build(int lx,int rx){
	node* x=new node();
	if(lx==rx){
		x->l=x->r=nullptr;
		if(s[lx]=='0'){
			x->a={0,0,0,1};
		}else{
			x->a={-1,1,0,0};
		}
	}else{
		x->l=build(lx,(lx+rx)/2);
		x->r=build((lx+rx)/2+1,rx);
		x->a=combine(x->l->a, x->r->a);
	}
	return x;
}
info query(node* v,int lx, int rx,int qlx,int qrx){
	if(rx<qlx || qrx<lx) return {-1,0,0,0};
	if(qlx<=lx && rx<=qrx) return v->a;
	return combine(query(v->l,lx,(lx + rx)/2,qlx,qrx),query(v->r,(lx+rx)/2+1,rx,qlx,qrx));
}
bool equal(info a, info b){
	if(a.lc==-1 && b.lc==-1) return true;
	return (a.lc==b.lc) && (a.rc==b.rc) && (a.x==b.x) && (a.y==b.y);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	A=rng();
	B=rng();
	C=rng();
	cin>>n>>s;
	node* segtree=build(0,n-1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b,l;
		cin>>a>>b>>l;
		a--;b--;
		bool ans=equal(query(segtree,0,n-1,a,a+l-1),query(segtree,0,n-1,b,b+l-1));
		cout<<(ans?"YES":"NO")<<'\n';
	}
}