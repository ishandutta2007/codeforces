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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3030;
int n,m,cnt,k;Pii a[N],s[N];ll res,cur;int sz;Vi era[N];
bool cmp(Pii x, Pii y){return x.se<y.se;}
int pre[N],nxt[N],pos[N],jmp[N];
inline void erase(int x){
	for(int cnt=1,u=pre[x];cnt<=k&&u;cnt++,u=pre[u])
		cur+=(pos[nxt[u]]-pos[u])*(pos[nxt[jmp[u]]]-pos[jmp[u]]),jmp[u]=nxt[jmp[u]];
	pre[nxt[x]]=pre[x];nxt[pre[x]]=nxt[x];pre[x]=nxt[x]=jmp[x]=0;
}
int main() {
	read(n);read(m);read(cnt);read(k);
	rep(i,1,cnt)read(a[i].fi),read(a[i].se);
	a[++cnt]=Pii(n+1,0);sort(a+1,a+cnt+1,cmp);
	rep(least,1,n){
		sz=0;rep(i,1,cnt)if(a[i].fi>=least)s[++sz]=a[i];
		rep(i,0,n)era[i].clear();rep(i,1,sz)era[s[i].fi].pb(i);
		rep(i,0,cnt)pre[i]=nxt[i]=jmp[i]=0;
		rep(i,1,sz-1)nxt[i]=i+1,pre[i+1]=i;
		rep(i,0,sz)pos[i]=i?s[i].se:m+1;cur=0;
		rep(i,1,sz){
			jmp[i]=i;rep(tt,1,k)jmp[i]=nxt[jmp[i]];
			int a=pos[jmp[i]]-pos[i]-1,b=pos[jmp[i]]-pos[nxt[i]];
			cur+=(a+b)*(a-b+1)/2;
		}
		per(i,n,least){
		//	cerr<<least<<' '<<i<<' '<<cur<<endl;
			res+=1LL*m*(m+1)/2-cur;
			rep(j,0,SZ(era[i])-1)erase(era[i][j]);
		}
	}
	cout<<res;
	return 0;
}