#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
const int N = 233333, mo = 1e9+9;
int n,k,x[N],y[N],fa[N],rt,f[N][2],mn[N],mx[N],lc[N],rc[N];Vi e[N];
struct dot{int x,y;}s[N];
bool cmp(dot a, dot b){return a.x<b.x;}
inline void gettree(){
	static int sta[N];int top=0;sta[++top]=1;
//	rep(i,1,n)printf("%d ",s[i].y);puts("");
	rep(i,2,n){
		int x=0;while(top&&s[sta[top]].y<s[i].y)x=sta[top--];
		if(top)fa[i]=sta[top];sta[++top]=i;if(x)fa[x]=i;
	}
	rep(i,1,n){e[fa[i]].pb(i);if(i<fa[i])lc[fa[i]]=i;else rc[fa[i]]=i;}
}
inline void DFS(int u){
	int m=-1e9;f[u][1]=1;mn[u]=u;mx[u]=u;
	per(i,SZ(e[u])-1,0){
		int v=e[u][i];DFS(e[u][i]);f[u][0]+=max(f[v][1],f[v][0]);
		f[u][1]+=max(f[v][1],f[v][0]);m=max(m,f[v][0]-max(f[v][1],f[v][0]));
		mn[u]=min(mn[u],mn[v]);mx[u]=max(mx[u],mx[v]);
	}
	f[u][1]+=m;
}
inline Pii solve(int k, int l, int r){
	if(!k||l>r)return Pii(-1e9,0);//!!! printf("%d %d %d %d QAQ \n",mn[k],mx[k],l,r);
	if(l<=mn[k]&&r>=mx[k])return Pii(f[k][0],f[k][1]);
	if(r<k){Pii t=solve(lc[k],l,r);return t;}
	if(l>k){Pii t=solve(rc[k],l,r);return t;}
	Pii res=Pii(0,1);Pii a=solve(lc[k],l,k-1),b=solve(rc[k],k+1,r);
	res.fi=max(max(a.se,a.fi),0)+max(max(b.se,b.fi),0);
	res.se=1+max(a.fi+max(max(b.se,b.fi),0),max(max(a.se,a.fi),0)+b.fi);
	return res;
}
int main() {
	read(n);read(k);rep(i,1,k)read(x[i]),read(y[i]);
	int a,b,c,d;read(a);read(b);read(c);read(d);
	rep(i,k+1,n)x[i]=(1LL*a*x[i-1]+b)%mo,y[i]=(1LL*c*y[i-1]+d)%mo;
	rep(i,1,n)s[i].x=x[i],s[i].y=y[i];sort(s+1,s+n+1,cmp);gettree();
	rep(i,1,n)x[i]=s[i].x,y[i]=s[i].y;
	rep(i,1,n)if(!fa[i])rt=i;DFS(rt);int q;read(q);
	while(q--){
		int l,r;read(l);read(r);
		l=lower_bound(x+1,x+n+1,l)-x;r=upper_bound(x+1,x+n+1,r)-x-1;
		Pii tmp=solve(rt,l,r);
		printf("%d\n",max(max(tmp.fi,tmp.se),0));
	}
	return 0;
}