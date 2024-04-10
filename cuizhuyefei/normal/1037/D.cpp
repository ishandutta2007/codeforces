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
int s[N],pos[N],vis[N];
Vi e[N];
bool cmp(int a, int b){return pos[a]<pos[b];}
int n,q[N];
int main() {
	read(n);rep(i,2,n){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,1,n)read(s[i]),pos[s[i]]=i;
	rep(i,1,n)sort(e[i].begin(),e[i].end(),cmp);
	int f=1,r=2;q[f]=1;vis[1]=1;
	while(f!=r){
		int u=q[f++],len=SZ(e[u]);
		rep(i,0,len-1)if(!vis[e[u][i]])vis[e[u][i]]=1,q[r++]=e[u][i];
	}
	rep(i,1,n)if(q[i]!=s[i]){printf("No");return 0;}
	printf("Yes");return 0;
}