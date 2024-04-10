#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 150,mo=998244353;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int flag;
struct Solver{
	ll a[205][N];int b[205][N],len[205],sz;
	void solve(){
		int t;read(t);flag+=t==100;while(t--){
			ll l,r;read(l);read(r);l--;r++;
			per(t,60,0)if((l>>t&1)!=(r>>t&1)){
				sz++;
				per(i,t-1,0)if(!(l>>i&1))a[sz][++len[sz]]=l^(1ll<<i),b[sz][len[sz]]=i;
				sz++;
				per(i,t-1,0)if((r>>i&1))a[sz][++len[sz]]=r^(1ll<<i),b[sz][len[sz]]=i;
				break;
			}
		}
	}
}a,b;
pair<ll,int>A[5000000];int len,qz[5000000],res;
bool cmp(const pair<ll,int>&a,const pair<ll,int>&b){return a.fi!=b.fi?a.fi<b.fi:a.se>b.se;}
inline void Get(ll x, int i){
//	printf("%lld %d\n",(x>>i)<<i,i);
	A[++len]=make_pair((x>>i)<<i,i);
}
int main() {
	a.solve();b.solve();
	rep(i,1,a.sz)rep(j,1,b.sz){//Set[max(a.b[i],b.b[j])].insert(Get(a.a[i]^b.a[j],max(a.b[i],b.b[j])));
	//	rep(x,1,a.len[i])rep(y,1,b.len[j])if(a.b[i][x]==b.b[j][y])
		/*for(int x=1;x<=a.len[i];x++)
			for(int y=1;y<=b.len[j];y++)
				Get(a.a[i][x]^b.a[j][y],max(a.b[i][x],b.b[j][y]));*/
		for(int x=1,y=1;x<=a.len[i];x++){
			while(y<=b.len[j]&&b.b[j][y]>a.b[i][x])y++;
			if(y<=b.len[j]&&a.b[i][x]==b.b[j][y])
				Get(a.a[i][x]^b.a[j][y],max(a.b[i][x],b.b[j][y]));
		}
		rep(x,1,a.len[i])if(b.len[j]&&a.b[i][x]>b.b[j][b.len[j]])
			Get(a.a[i][x]^b.a[j][b.len[j]],a.b[i][x]);
		rep(y,1,b.len[j])if(a.len[i]&&b.b[j][y]>a.b[i][a.len[i]])
			Get(b.a[j][y]^a.a[i][a.len[i]],b.b[j][y]);
	}
	sort(A+1,A+len+1,cmp);len=unique(A+1,A+len+1)-A-1;
//	rep(i,1,len)printf("%lld %d\n",A[i].fi,A[i].se);
	rep(i,1,len){
		int l=i+1,r=lower_bound(A+1,A+len+1,make_pair(A[i].fi+(1ll<<A[i].se),int(1e9)),cmp)-A-1;
		if(l<=r)qz[l]++,qz[r+1]--;
	}
	rep(i,1,len)qz[i]+=qz[i-1];
	rep(j,1,len)if(!qz[j]){
		ll val=A[j].fi;int d=A[j].se;
	//	printf("%lld %d\n",val,d);
		res=(res+1ll*val%mo*((1ll<<d)%mo)%mo)%mo;
		if(d)res=(res+1ll*((1ll<<d)-1)%mo*((1ll<<d-1)%mo))%mo;
	}
//	if(flag)return 0;
	/*rep(d,0,60)for(auto x:Set[d]){
		bool gg=0;ll val=x;
		rep(i,d+1,60){x^=(x&(1ll<<(i-1)));if(Set[i].count(x)){gg=1;break;}}
		if(!gg){
			res=(res+1ll*val%mo*((1ll<<d)%mo)%mo)%mo;
			if(d)res=(res+1ll*((1ll<<d)-1)%mo*((1ll<<d-1)%mo))%mo;
		}
	}*/
	cout<<res;
	return 0;
}