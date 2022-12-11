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
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
const int INF=1e9;

int n;
bool mp[8010][8010];

ll work(int *p,int m){
	if (m==1) return 0;
	//printf("S: "); rep(i,1,m) printf("%d ",p[i]); puts("");
	ll W=0;
	const int o=p[1];
	static bool mrk[8010],ok[8010];
	rep(i,1,m) ok[p[i]]=1;
	rep(i,1,m) if (mp[p[i]][o]) mrk[p[i]]=1;
	static int d[8010],c[8010];
	rep(i,1,n) if (ok[i]) rep(j,1,n) if (ok[j]) if (mp[i][j]&&!(!mrk[i]&&mrk[j])) ++d[j];
	static int que[8010],hd,tl;
	rep(i,1,n) if (ok[i]&&!d[i]) que[++tl]=i;
	while (hd<tl){
		const int u=que[++hd];
		rep(v,1,n) if (ok[v]&&mp[u][v]&&!--d[v]) que[++tl]=v;
	}
	assert(tl==m);
	static int id[8010];
	rep(i,1,m) id[que[i]]=i;
	const int M=id[o];
	assert(~M);
	assert(M>1);
	assert(M<m);
	rep(i,1,M){
		const int x=que[i];
		rep(j,1,m) c[j]=d[j]=INF;
		d[i]=0;
		int y=-1;
		rep(j,M+1,m) if (mp[x][que[j]]){y=que[j];d[j]=min(d[j],1);}
		if (~y){
			rep(j,1,M) if (mp[y][que[j]]) d[j]=min(d[j],2);
		}
		y=que[m];
		rep(j,1,M) if (mp[y][que[j]]) d[j]=min(d[j],3);
		rep(j,M+1,m) if (mp[o][que[j]]) d[j]=min(d[j],2);
		rep(j,1,m){
			if (j^M) c[j+1]=min(c[j+1],min(c[j],d[j]+1));
			W+=min(c[j],d[j]);
		}
	}
	memset(mrk,0,sizeof mrk);
	rep(i,M+1,m){
		const int x=que[i];
		rep(j,1,m) c[j]=d[j]=INF;
		d[i]=0;
		rep(j,1,M) if (mp[x][que[j]]&&!mrk[j]){
			mrk[j]=1;
			const int y=que[j];
			rep(k,M+1,m) mrk[k]=mrk[k]||mp[y][que[k]];
		}
		rep(j,M+1,m) if (mrk[j]) d[j]=min(d[j],2); else d[j]=min(d[j],3);
		rep(j,1,M) if (mp[x][que[j]]) d[j]=min(d[j],1);
		const int y=que[m];
		rep(j,1,M) if (mp[y][que[j]]) d[j]=min(d[j],2);
		rep(j,1,m){
			if (j^M) c[j+1]=min(c[j+1],min(c[j],d[j]+1));
			W+=min(c[j],d[j]);
		}
	}
	return W;
}

void solve(){
	n=read();
	rep(i,1,n){
		static char s[2010];
		scanf("%s",s+1);
		rep(j,1,n>>2){
			const int t=isdigit(s[j])?s[j]-'0':10+s[j]-'A';
			mp[i][(j<<2)-3]=t>>3&1;
			mp[i][(j<<2)-2]=t>>2&1;
			mp[i][(j<<2)-1]=t>>1&1;
			mp[i][(j<<2)]=t&1;
		}
	}
	//rep(i,1,n) rep(j,1,n) putchar(mp[i][j]^48),(j==n?puts(""):0);
	static int p[8010],d[8010];
	rep(i,1,n) rep(j,1,n) d[i]+=mp[i][j];
	rep(i,1,n) p[i]=i;
	sort(p+1,p+n+1,[&](const int &x,const int &y){return d[x]<d[y];});
	int q=-1; int S=0;
	rep(i,1,n){
		S+=d[p[i]];
		if (S==i*(i-1)/2){
			q=i; break;
		}
	}
	ll ans=0;
	rep(i,q+1,n){
		ans+=i-1+614LL*n*(n-i);
	}
	ans+=614LL*n*q*(n-q);
	ans+=work(p,q);
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}