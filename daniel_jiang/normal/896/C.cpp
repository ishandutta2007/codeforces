// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

inline ll pw(ll x,ll y,ll mod){
	ll sum=1;x%=mod;
	while(y){
		if(y&1) sum=(sum*x)%mod;
		x=(x*x)%mod;y>>=1;
	}
	return sum;
}

// ---------- IO ---------- //

const int N=1e5+5;
int n,m,maxv,a[N],seed;

inline int rnd(){  // rt
	int tmp=seed;
	seed=((ll)seed*7+13)%1000000007;
	return tmp;
}
struct range{
	int l,r;mutable ll v;
	range(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator < (range x) const{return l<x.l;}
};

struct Old_Driver_Tree{
	set<range> qaq;
	#define IT set<range>::iterator
	vector<pair<ll,int> > qwq;
	inline IT split(int pos){  //   pos  
		IT tmp=qaq.lower_bound(range(pos));
		if(tmp!=qaq.end()&&tmp->l==pos) return tmp;
		--tmp;int l=tmp->l,r=tmp->r;ll v=tmp->v;
		qaq.erase(tmp);qaq.insert(range(l,pos-1,v));
		return qaq.insert(range(pos,r,v)).first;
	}
	inline void assign(int l,int r,ll v){  //  
		IT R=split(r+1),L=split(l);
		qaq.erase(L,R);qaq.insert(range(l,r,v));
	}
	inline void add(int l,int r,ll v){  //  
		IT R=split(r+1),L=split(l);
		while(L!=R) L->v+=v,++L;
	}
	inline ll pw_sum(int l,int r,ll k,ll p){  //  k   p 
		ll ans=0;IT R=split(r+1),L=split(l);
		while(L!=R) ans=(ans+(ll)(L->r-L->l+1)*pw(L->v,k,p)%p)%p,++L;
		return ans;
	}
	inline ll kth(int l,int r,int k){  //  k  
		IT R=split(r+1),L=split(l);qwq.clear();
		while(L!=R) qwq.pb(pair<ll,int>(L->v,L->r-L->l+1)),++L;
		sort(qwq.begin(),qwq.end());
		for(vector<pair<ll,int> >::iterator it=qwq.begin();it!=qwq.end();it++){
			k-=it->second;
			if(k<=0) return it->first;
		}
	}
}ODT;

// ---------- ODT ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);rd(seed);rd(maxv);
	for(re i=1;i<=n;++i) a[i]=(rnd()%maxv)+1,ODT.qaq.insert(range(i,i,a[i]));ODT.qaq.insert(range(n+1,n+1,0));
	int op,l,r,x,y;
	for(re i=1;i<=m;i++){
		op=(rnd()%4)+1;l=(rnd()%n)+1;r=(rnd()%n)+1;
		if(l>r) l^=r^=l^=r;
		if(op==3) x=(rnd()%(r-l+1))+1;
		else x=(rnd()%maxv)+1;
		if(op==4) y=(rnd()%maxv)+1;
		// rt
		if(op==1) ODT.add(l,r,x);
		else if(op==2) ODT.assign(l,r,x);
		else if(op==3) wr(ODT.kth(l,r,x)),puts("");
		else wr(ODT.pw_sum(l,r,x,y)),puts("");
	}
	return 0;
}

// ---------- Main ---------- //