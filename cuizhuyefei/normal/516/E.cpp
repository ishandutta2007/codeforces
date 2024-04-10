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
typedef pair<int,ll> Pii;
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
const int N = 266666;
int n,m,g;ll res;
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
inline void exgcd(int a, int b, int &x, int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,y,x);y-=a/b*x;
}
struct Solver{
	int n,m;
	void ini(int nn, int mm){n=nn;m=mm;}
	vector<Pii>a[N];set<int>Set[N];
	inline void addans(int p, int time, int special){
		int bel=p%g;int x,y;exgcd(m/g,n/g,x,y);
		x=1LL*x*((p-bel)/g)%(n/g);
		a[bel].pb(Pii(x,time));
		if(special==0)Set[bel].insert(x);
	}
	void solve(){
		rep(i,0,g-1)if(!SZ(a[i])){puts("-1");exit(0);}
		rep(i,0,g-1)sort(a[i].begin(),a[i].end());
		rep(j,0,g-1){
		//	cerr<<j<<' '<<SZ(a[j])<<endl;
			int p=0;rep(i,0,SZ(a[j])-1)if(a[j][i].se<a[j][p].se)p=i;
			for(int t=p;;t=t+1<SZ(a[j])?t+1:0){
			//	cerr<<t<<endl;
				if(t+1<SZ(a[j]))umin(a[j][t+1].se,a[j][t].se+1LL*m*(a[j][t+1].fi-a[j][t].fi));
				else umin(a[j][0].se,a[j][t].se+1ll*m*(a[j][0].fi-a[j][t].fi+n/g));
				if((t+1<SZ(a[j])?t+1:0)==p)break;
			}
			rep(i,0,SZ(a[j])-1){
			//	cerr<<i<<endl;
				if(!Set[j].count(a[j][i].fi))umax(res,a[j][i].se);int t=i;
				if(i+1<SZ(a[j])){
					if(a[j][i+1].fi-a[j][i].fi>1)
						umax(res,a[j][t].se+1LL*m*(a[j][t+1].fi-a[j][t].fi)-m);
				}
				else{
					if(a[j][0].fi-a[j][t].fi+n/g>1)
						umax(res,a[j][t].se+1ll*m*(a[j][0].fi-a[j][t].fi+n/g)-m);
				}
			}
		}
	//	cerr<<"fin\n";
	}
}A,B;
int main() {
	read(n);read(m);g=gcd(n,m);A.ini(n,m);B.ini(m,n);
	if(g>2e5){puts("-1");return 0;}
	int l;read(l);while(l--){
		int x;read(x);A.addans(x,x,0);B.addans(x%m,x,x);
	}
	read(l);while(l--){
		int x;read(x);B.addans(x,x,0);A.addans(x%n,x,x);
	}
	A.solve();B.solve();cout<<res;
	return 0;
}