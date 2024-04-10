#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
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
/*
typedef pair<int,int> P;
*/
#define rep(i,l,r) for (int i(l);i<=(r);i++)
#define per(i,l,r) for (int i(r);i>=(l);i--)

int n,m,q,p[30010];
ll binom(int n,int m){
	ll res=1;
	rep(i,0,m-1) res*=n-i;
	rep(i,1,m) res/=i;
	return res;
}
ll b[5][30010];
int L[5][30010],R[5][30010];
struct C{
	int l,r; ll w;
}c[5][300010];
bool operator<(const C &x,const C &y){
	return x.w<y.w;
}
bool cmp(const int &x,const int &y){return p[x]<p[y];}
void solve(){  //init
	n=read(),m=read(),q=read();
	rep(i,1,n) p[i]=read();
	rep(i,0,m) c[i][L[i][n+1]=R[i][n+1]=150003]=(C){-1,-1,1};
	rep(j,0,m) b[j][0]=1;
	rep(i,1,n){
		rep(j,0,m) b[j][i]=binom(i-1,j);
		rep(j,1,m) b[j][i]+=b[j-1][i];
	}
	per(i,1,n){
		rep(j,0,m){
			L[j][i]=L[j][i+1],R[j][i]=R[j][i+1];
			static int f[6],ftop,g[6],gtop; ftop=gtop=0;
			rep(k,1,min(j,n-i))
				if (p[i+k]<p[i]) f[++ftop]=i+k;
				else g[++gtop]=i+k;
			sort(f+1,f+ftop+1,cmp); sort(g+1,g+gtop+1,cmp);
			per(_k,1,ftop){
				int k=f[_k]-i;
				c[j][--L[j][i]]=(C){i,i+k,b[j-k][n-i-k]};
			}
			rep(_k,1,gtop){
				int k=g[_k]-i;
				c[j][++R[j][i]]=(C){i,i+k,b[j-k][n-i-k]};
			}
//			rep(k,1,min(j,n-i)){
//				if (p[i+k]<p[i]) c[j][--L[j][i]]=(C){i,i+k,b[j-k][n-i-k]};
//				else c[j][++R[j][i]]=(C){i,i+k,b[j-k][n-i-k]};
//			}
		}
	}
	rep(j,0,m){
		rep(i,L[j][1],R[j][1]) c[j][i].w+=c[j][i-1].w;
	}
//	rep(j,0,m){
//		rep(i,L[j][1],R[j][1]) printf("c %d %d: %d %d %lld\n",j,i,c[j][i].l,c[j][i].r,c[j][i].w);
//		puts("");
//	}
	while (q--){
		int x=read(); ll rk=read();
		if (rk>b[m][n]){puts("-1");continue;}
		int e=m,p=1,ans=-1;
		while (1){
			rk+=c[e][L[e][p]-1].w;
			int t=lower_bound(c[e]+L[e][p],c[e]+R[e][p]+1,(C){-1,-1,rk})-c[e];
			assert(t<=R[e][p]); const C &V=c[e][t];
			if (V.l==-1){ans=::p[x];break;}
			if (V.l<=x&&x<=V.r){ans=::p[V.l+V.r-x];break;}
			rk-=c[e][t-1].w;
			e-=V.r-V.l; p=V.r+1;
		}
		assert(~ans); //assert(rk==1);
		printf("%d\n",ans);
//		printf("rk %lld\n",rk);
	}
}
int main()
{
	for (int T=read();T--;) solve();
}