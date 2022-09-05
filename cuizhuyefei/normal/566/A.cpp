#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 888888;
char s[N];
int n,ch[N][26],dep[N],cnt=1;Vi a[N],b[N];ll res;int ans1[N],ans2[N],len;
inline int ins(char *s, int n){
	int now=1;rep(i,1,n){
		int c=s[i]-'a';
		if(!ch[now][c])ch[now][c]=++cnt;now=ch[now][c];dep[now]=i;
	}
	return now;
}
void dfs(int u){
	rep(i,0,25)if(ch[u][i]){
		dfs(ch[u][i]);int v=ch[u][i];
		per(j,SZ(a[v])-1,0)a[u].pb(a[v][j]);
		per(j,SZ(b[v])-1,0)b[u].pb(b[v][j]);
	}
	while(SZ(a[u])&&SZ(b[u])){
		res+=dep[u];len++;ans1[len]=a[u].back();ans2[len]=b[u].back();
		a[u].pop_back();b[u].pop_back();
	}
}
int main() {
	read(n);rep(i,1,n){
		scanf("%s",s+1);int l=strlen(s+1);a[ins(s,l)].pb(i);
	}
	rep(i,1,n){
		scanf("%s",s+1);int l=strlen(s+1);b[ins(s,l)].pb(i);
	}
	dfs(1);printf("%lld\n",res);rep(i,1,len)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}