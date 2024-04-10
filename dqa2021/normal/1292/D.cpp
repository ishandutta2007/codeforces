#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
bool vis[5010]; int prm[5010],d[5010];
void sieve(int x){
	rep(i,2,x){
		if (!vis[i]) prm[++*prm]=i,d[i]=i;
		rep(j,1,*prm){
			int t=i*prm[j];
			if (t>x) break;
			vis[t]=1; d[t]=prm[j];
			if (i%prm[j]==0) break;
		}
	}
	//rep(i,1,x) printf("d %d = %d\n",i,d[i]);
}

int n; const int m=5000;
int c[5010];
int b[5010][5010],p[5010];
bool ban[5010];
int getlcs(int x){
	if (ban[x]) return -1;
	while (p[x]&&b[x][p[x]]==b[0][p[x]]) --p[x];
	if (!p[x]) return ban[x]=1,-1;
	return p[x];
}

void solve(){
	n=read();
	rep(_,1,n) ++c[read()];
	sieve(m);
	rep(i,2,m){
		memcpy(b[i],b[i-1],sizeof b[i]);
		int w=i;
		while (w^1) b[i][d[w]]++,w/=d[w];
	}
	rep(i,1,m) p[i]=m;
	
	static int e[5010];
	ll W=0;
	rep(i,1,m) rep(j,1,m) W+=1LL*b[i][j]*c[i];
	while (1){
		rep(i,1,m){
			const int w=getlcs(i);
			//if (c[i]) printf("  lcs %d: %d\n",i,w);
			if (!~w) continue;
			e[w]=0;
		}
		int S=-1;
		rep(i,1,m){
			const int w=getlcs(i);
			if (!~w) continue;
			e[w]+=c[i];
			//if (e[w]) printf("  e %d upd to %d\n",w,e[w]);
			if (e[w]*2>n) S=w;
		}
		//printf("test S %d\n",S);
		if (!~S) break;
		W-=e[S]*2-n;
		rep(i,1,m) ban[i]=getlcs(i)!=S;
		++b[0][S];
		//printf("step %d\n",S);
	}
	printf("%lld\n",W);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}