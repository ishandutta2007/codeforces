#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 220;
const ll inf = 1e16;
int n,a[N],sz;
ll val[N];
struct mtr {
	ll v[N][N];
	mtr() {rep(i,0,N-1) rep(j,0,N-1) v[i][j]=-inf;}
} zy,ans;
inline void mul(mtr &a, mtr b) {
	mtr c;
	rep(i,0,sz) rep(j,0,sz) rep(k,0,sz) c.v[i][j]=max(c.v[i][j],a.v[i][k]+b.v[k][j]);
	a=c;
}
char s[N];
struct AC {
	int sz,ch[N][26],f[N];
	inline void ins(char *s, int n, int v) {
		int now=0;
		for (int i=1; i<=n; i++) {
			int c=s[i]-'a';
			if (!ch[now][c]) ch[now][c]=++sz;
			now=ch[now][c];
		}
		val[now]+=v;
	}
	inline void getfail() {
		queue<int> q;
		rep(i,0,25) if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int u=q.front(); q.pop();
			rep(i,0,25) if (ch[u][i]) {
				int v=ch[u][i],x=f[u]; q.push(v);
				while (x&&!ch[x][i]) x=f[x];
				f[v]=ch[x][i]; val[v]+=val[f[v]];
			}
		}
		rep(i,0,sz) rep(j,0,25) {
			int u=i;
			while (u&&!ch[u][j]) u=f[u];
			zy.v[i][ch[u][j]]=val[ch[u][j]];
		//	if (val[ch[u][j]]) 
		//	printf("%d %d: %d\n",i,ch[u][j],val[ch[u][j]]);
		}
	}
} ac;
int main() {
	read(n); ll l; scanf("%lld",&l);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) {scanf("%s",s+1); int l=strlen(s+1); ac.ins(s,l,a[i]);}
	ac.getfail(); sz=ac.sz; rep(i,0,sz) ans.v[i][i]=0;
	while (l) {
		if (l&1) mul(ans,zy);
		mul(zy,zy);
		l>>=1;
	}
	ll res=0; rep(i,0,sz) res=max(res,ans.v[0][i]);
	cout<<res;
	return 0;
}