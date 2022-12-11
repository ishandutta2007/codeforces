#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
typedef pair<ll,ll> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
const ll INF=8e18;

int n; ll C;
ll w[1000010];

ll k=1,b;
P que[2000100]; ll hd=1000050,tl=hd-1;

/*struct D{
	ll *p,v;
}; vector<D> d[1000010],*E;*/

P get_back(){
	assert(hd<=tl);
	if (k==1) return P(que[tl].fi+b,que[tl].se+b);
	return P(-que[hd].se+b,-que[hd].fi+b);
}
void pop_back(){
	assert(hd<=tl);
	//if (k==1) E->pb((D){&tl,tl}),--tl;
	//else E->pb((D){&hd,hd}),++hd;
	if (k==1) --tl;
	else ++hd;
}
bool empty(){return hd>tl;}
void push_back(P v){
	if (k==1){
		//E->pb((D){&tl,tl});
		//E->pb((D){que+tl+1,que[tl+1]});
		v.fi-=b,v.se-=b;
		que[++tl]=v;
	}
	else{
		//E->pb((D){&hd,hd});
		//E->pb((D){que+hd-1,que[hd-1]});
		v.fi-=b,v.se-=b;
		v.fi=-v.fi,v.se=-v.se;
		swap(v.fi,v.se);
		que[--hd]=v;
	}
}
void settag(ll _k,ll _b){
	//E->pb((D){&k,k});
	//E->pb((D){&b,b});
	k*=_k,b*=_k,b+=_b;
}

ll ans[1000010];

ll id[1000010];

void solve(){
	n=read(),C=read();
	rep(i,1,n-2) w[i]=read();
	que[++tl]=P(0,w[1]);
	rep(i,1,n-2){  // - (i+1) + (i+2)
		const ll W=w[i]; //E=d+i;
		while (!empty()){
			const P v=get_back();
			if (v.fi>W){pop_back(); continue;}
			pop_back(); push_back(P(v.fi,min(v.se,W)));
			break;
		}
		if (empty()) puts("NO"),exit(0);
		id[i]=get_back().se;
		if (get_back().se==W){
			//while (!empty()) pop_back();
			hd=1000050,tl=hd-1;
			k=1,b=0;
			push_back(P(0,W));
			id[i]=-1;
		}
		else{
			settag(-1,W);
			if (get_back().se!=W) push_back(P(W,W));
		}
		/*printf("Case %d:",i);
		if (k==1){
			rep(j,hd,tl) printf(" %lld,%lld",que[j].fi+b,que[j].se+b);
		}
		else{
			per(j,hd,tl) printf(" %lld,%lld",-que[j].se+b,-que[j].fi+b);
		}
		puts("");*/
	}
	puts("YES");
	ll o=get_back().se,s=1;
	ans[n]=o*s;
	per(i,1,n-2){
		//E=d+i;
		//reverse(E->begin(),E->end());
		//for (const D &v: *E) *v.p=v.v;
		if (id[i]==-1) o=w[i],s=-s;
		else if (o==w[i]) o=id[i],s=-s;
		else o=w[i]-o;
		ans[i+1]=o*s;
	}
	//rep(i,1,n) printf("d %d = %lld\n",i,ans[i]);
	rep(i,2,n) ans[i]+=ans[i-1];
	ll mn=INF;
	rep(i,1,n) mn=min(mn,ans[i]);
	rep(i,1,n) printf("%lld ",ans[i]-mn);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}