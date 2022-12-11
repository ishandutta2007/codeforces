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
#define NO puts("No"),exit(0)

int n,k;
vector<int> e[200010];

int fat[200010],dep[200010],maxd[200010];
void dfs(int x,int f,int d){
	fat[x]=f; dep[x]=maxd[x]=d;
	forall(x,y) if (y^f)
		dfs(y,x,d+1),maxd[x]=max(maxd[x],maxd[y]);
}

int col[200010];

void dfs1(int x,int f,int c){
	col[x]=c; c=c==1?k:c-1;
	forall(x,y) if (y^f) dfs1(y,x,c);
}

void dfs2(int x,int f,int c){
	col[x]=c; c=c==k?1:c+1;
	forall(x,y) if (y^f) dfs2(y,x,c);
}



void solve(){
	n=read(),k=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	if (k==2){
		const function<void(int,int,int)> dfs=[&](int x,int f,int c){
			col[x]=c;
			forall(x,y) if (y^f) dfs(y,x,3-c);
		};
		dfs(1,0,1);
		puts("Yes");
		rep(i,1,n) printf("%d ",col[i]);
		puts("");
		return;
	}
	static int g[200010],m;
	{
	dfs(1,0,1);
	const int S=max_element(dep+1,dep+n+1)-dep;
	dfs(S,0,1);
	const int T=max_element(dep+1,dep+n+1)-dep;
	
	for (int i=T;i;i=fat[i]) g[++m]=i;
	reverse(g+1,g+m+1);
	}
	
	if (m<k){
		puts("Yes");
		rep(i,1,n) printf("1 ");
		puts("");
		return;
	}
	
	if (m&1){
		const int o=g[m+1>>1];
		dfs(o,0,0);
		vector<int> S;
		forall(o,y) S.pb(maxd[y]);
		sort(all(S)); reverse(all(S));
		if (S.size()>2&&S[1]+S[2]>=k-1) NO;
		rep(i,1,n) if (i^o){
			S.clear();
			forall(i,j)
				if (j^fat[i]) S.pb(maxd[j]-dep[i]);
				else S.pb((m>>1)+dep[i]);
			sort(all(S)); reverse(all(S));
			if (S.size()>2&&S[1]+S[2]>=k-1) NO;
		}
		puts("Yes");
		col[o]=1;
		forall(o,y)
			if (y==g[m>>1]) dfs1(y,o,k);
			else dfs2(y,o,2);
		rep(i,1,n) printf("%d ",col[i]);
		puts("");
		return;
	}
	const int u=g[m>>1],v=g[m+2>>1];
	dfs(u,v,0);
	dfs(v,u,0);
	vector<int> S;
	rep(i,1,n){
		S.clear();
		forall(i,j)
			if (j^fat[i]) S.pb(maxd[j]-dep[i]);
			else S.pb((m>>1)+dep[i]);
		sort(all(S)); reverse(all(S));
		if (S.size()>2&&S[1]+S[2]>=k-1) NO;
	}
	puts("Yes");
	dfs1(u,v,1); dfs2(v,u,2);
	rep(i,1,n) printf("%d ",col[i]);
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}