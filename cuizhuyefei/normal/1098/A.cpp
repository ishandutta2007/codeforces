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
const int N = 666666;
int n,fa[N],s[N];ll res;Vi e[N];
void dfs(int u){
	if(s[u]<0){
		s[u]=2e9;rep(i,0,SZ(e[u])-1)s[u]=min(s[u],s[e[u][i]]);
		if(!SZ(e[u]))s[u]=s[fa[u]];
	}
	res+=s[u]-s[fa[u]];if(s[u]<s[fa[u]]){puts("-1");exit(0);}
	rep(i,0,SZ(e[u])-1)dfs(e[u][i]);
}
int main() {
	read(n);rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	rep(i,1,n)read(s[i]);dfs(1);cout<<res;
	return 0;
}