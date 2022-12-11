#include<bits/stdc++.h>
#define pb push_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m,lim;
char _mp[400010];
char mp(int x,int y){
	return _mp[(x-1)*m+y];
}
int H(int x,int y){
	return (x-1)*m+y;
}

int a[400010];
int mn[400010],mx[400010];
int que[400010],hd,tl;
bool vis[400010];

void work1(){
	memset(vis,0,sizeof vis); hd=tl=0;
	rep(j,1,m){
		rep(i,1,n) if (mp(i,j)=='#'&&!vis[H(i,j)]) vis[H(i,j)]=1,mn[H(i,j)]=j,que[++tl]=H(i,j);
		while (hd<tl){
			int u=que[++hd];
//			printf("u %d mn %d %d = %d j %d\n",u,(u-1)/n+1,(u-1)%n+1,mn[u],j);
			if ((u-1)%m+1!=1&&_mp[u-1]=='#'&&!vis[u-1]){
				vis[u-1]=1,mn[u-1]=j,que[++tl]=u-1;
			}
			if ((u-1)%m+1!=m&&_mp[u+1]=='#'&&!vis[u+1]){
				vis[u+1]=1,mn[u+1]=j,que[++tl]=u+1;
			}
			if (u+m<=lim&&!vis[u+m]){
				vis[u+m]=1,mn[u+m]=j,que[++tl]=u+m;
			}
			if (u-m>0&&!vis[u-m]&&_mp[u]=='#'&&_mp[u-m]=='#'){
				vis[u-m]=1,mn[u-m]=j,que[++tl]=u-m;
			}
		}
	}
}

void work2(){
	memset(vis,0,sizeof vis); hd=tl=0;
	per(j,1,m){
		rep(i,1,n) if (mp(i,j)=='#'&&!vis[H(i,j)]) vis[H(i,j)]=1,mx[H(i,j)]=j,que[++tl]=H(i,j);
		while (hd<tl){
			int u=que[++hd];
//			printf("u %d mx %d %d = %d j %d\n",u,(u-1)/n+1,(u-1)%n+1,mx[u],j);
			if ((u-1)%m+1!=1&&_mp[u-1]=='#'&&!vis[u-1]){
				vis[u-1]=1,mx[u-1]=j,que[++tl]=u-1;
			}
			if ((u-1)%m+1!=m&&_mp[u+1]=='#'&&!vis[u+1]){
				vis[u+1]=1,mx[u+1]=j,que[++tl]=u+1;
			}
			if (u+m<=lim&&!vis[u+m]){
				vis[u+m]=1,mx[u+m]=j,que[++tl]=u+m;
			}
			if (u-m>0&&!vis[u-m]&&_mp[u]=='#'&&_mp[u-m]=='#'){
				vis[u-m]=1,mx[u-m]=j,que[++tl]=u-m;
			}
		}
	}
}

void solve(){
	n=read(),m=read(); lim=n*m;
	rep(i,1,n) scanf("%s",_mp+(i-1)*m+1);
	rep(i,1,m) a[i]=read();
	work1(); work2();
	vector<P> S;
	rep(j,1,m){
		int t=0;
		if (!a[j]) continue;
		per(i,1,n){
			if (mp(i,j)=='#'){
				++t;
				if (t==a[j]){
					S.emplace_back(mn[H(i,j)],mx[H(i,j)]);
					break;
				}
			}
		}
	}
	sort(all(S),[](P x,P y){return x.se<y.se;});
	int z=0,R=0;
	for (const P &o: S){
//		printf("test %d %d\n",o.fi,o.se);
		if (o.fi>R) ++z,R=o.se;
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}