#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
//typedef pair<int,int> P;
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
const int B=310,N=1e5;

int n,q;
int f[100010],g[100010];
int tag[N/B+10],mrk[N/B+10];

int get_f(int x){
	if (x==1) return 0;
	const int y=(x-1)/B;
	return max(1,f[x]-tag[y]);
}

void upd_g(int b){
	if (mrk[b]>=B) return;
	const int l=b*B+1,r=min(n,(b+1)*B);
	rep(i,l,r){
		const int f=get_f(i);
		if (f>=l) g[i]=g[f];
		else g[i]=f;
	}
}

int get_g(int x){
	const int y=(x-1)/B;
	if (mrk[y]>=B) return get_f(x);
	return g[x];
}

void solve(){
	n=read(),q=read();
	rep(i,2,n) f[i]=read();
	for (int i=1,j=0;i<=n;i+=B,++j) upd_g(j);
	while (q--){
		if (read()&1){
			int l=read(),r=read(),d=read();
			const int L=(l-1)/B,R=(r-1)/B;
			if (L==R){
				rep(i,l,r) f[i]=max(1,f[i]-d);
				upd_g(L);
			}
			else{
				int lim=(L+1)*B;
				rep(i,l,lim) f[i]=max(1,f[i]-d);
				upd_g(L);
				rep(i,L+1,R-1) tag[i]=min(tag[i]+d,n),++mrk[i],upd_g(i);
				lim=R*B+1;
				rep(i,lim,r) f[i]=max(1,f[i]-d);
				upd_g(R);
			}
			continue;
		}
		int u=read(),v=read();
		if (u==v){printf("%d\n",u);continue;}
		int a=u,b=v;
		while (u^v){
			//printf("test u %d v %d\n",u,v);
			if (u<v) b=v,v=get_g(v);
			else a=u,u=get_g(u);
		}
		u=a,v=b; int l=-1;
		//printf("test' u %d v %d\n",u,v);
		static int vrn[100010],tim; ++tim;
		while (1){
			//printf("test'' u %d v %d\n",u,v);
			if (u==v){l=u;break;}
			if (u&&vrn[u]==tim){l=u;break;}
			if (v&&vrn[v]==tim){l=v;break;}
			if (u) vrn[u]=tim,u=get_f(u);
			if (v) vrn[v]=tim,v=get_f(v);
		}
		assert(~l);
		printf("%d\n",l);
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}