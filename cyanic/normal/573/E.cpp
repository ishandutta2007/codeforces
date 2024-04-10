#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

/*
f[0][0]
f[i][j]=max(f[i-1][j],f[i-1][j-1]+(ll)j*a[i]);
 i k 
0 <= j <= k,	f[i][j]=f[i-1][j]
k < j <= i,		f[i][j]=f[i-1][j-1]+j*a[i]
*/

const int N=500005;
namespace T{
	#define L t[o].lc
	#define R t[o].rc
	struct node{
		int lc,rc,key,sz;
		ll val,k,b;
	}t[N];
	int rt,sz;
	inline int nw(const ll v){
		t[++sz].val=v;
		t[sz].sz=1,t[sz].key=rand();
		return sz;
	}
	inline void up(const int &o){
		t[o].sz=t[L].sz+1+t[R].sz;
	}
	inline void app(const int &o,const ll k,const ll b){
		t[o].val+=b+k*t[L].sz;
		t[o].k+=k,t[o].b+=b;
	}
	inline void down(const int &o){
		if(t[o].k||t[o].b){
			if(L)app(L,t[o].k,t[o].b);
			if(R)app(R,t[o].k,t[o].b+t[o].k*(t[L].sz+1));
			t[o].k=t[o].b=0;
		}
	}
	int merge(int x,int y){
		if(!x||!y)return x|y;
		down(x),down(y);
		if(t[x].key<t[y].key){
			t[x].rc=merge(t[x].rc,y);
			return up(x),x;
		}
		t[y].lc=merge(x,t[y].lc);
		return up(y),y;
	}
	pii split(int x,int k){
		if(!x||!k)return mp(0,x);
		if(k==t[x].sz)return mp(x,0);
		down(x);
		if(k<=t[t[x].lc].sz){
			pii y=split(t[x].lc,k);
			t[x].lc=y.se,y.se=x;
			return up(x),y;
		}
		pii y=split(t[x].rc,k-t[t[x].lc].sz-1);
		t[x].rc=y.fi,y.fi=x;
		return up(x),y;
	}
	ll Kth(int k){
		int o=rt; k++;
		for(;;){
			down(o);
			if(k==t[L].sz+1)return t[o].val;
			if(k<=t[L].sz)o=L;
			else k-=t[L].sz+1,o=R;
		}
	}
	void init(){
		rt=nw(0);
	}
	void ins(int k,ll v){
		pii x=split(rt,k);
		rt=merge(x.fi,merge(nw(v),x.se));
	}
	void add(int k,ll v){
		pii x=split(rt,k);
		app(x.se,v,k*v);
		rt=merge(x.fi,x.se);
	}
	ll dfs(int o){
		ll res=t[o].val;
		down(o);
		if(L)res=max(res,dfs(L));
		if(R)res=max(res,dfs(R));
		return res;
	}
	void print(int o){
		down(o);
		if(L)print(L);
		printf("%lld ",t[o].val);
		if(R)print(R);
	}
}
int a[N],n;

int main(){
	read(n),T::init();
	rep(i,1,n){
		read(a[i]);
		int l=0,r=i-1;
		for(int mid;l<r;){
			mid=(l+r+1)>>1;
			if(T::Kth(mid)>=T::Kth(mid-1)+(ll)mid*a[i])
				l=mid;
			else
				r=mid-1;
		}
		T::ins(l+1,T::Kth(l));
		T::add(l+1,a[i]);
		//T::print(T::rt),puts("");
	}
	cout<<T::dfs(T::rt)<<endl;
	return 0;
}