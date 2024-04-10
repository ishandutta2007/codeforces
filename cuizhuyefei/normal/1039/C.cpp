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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1234567,mo=1e9+7;
ll n,m,k,c[N],res,f[N],mi[N];Vi tmp;
struct E{ll c;ll u,v;}e[N];
bool cmp(E a, E b){return a.c<b.c;}
int find(int x){tmp.pb(x);return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	read(n);read(m);read(k);
	rep(i,1,n)read(c[i]);
	rep(i,1,m){
		read(e[i].u);read(e[i].v);e[i].c=c[e[i].u]^c[e[i].v];
	}
	rep(i,1,n)f[i]=i;ll cnt=n;//res=(1LL<<k)%mo*((1LL<<n)%mo)%mo;
	mi[0]=1;rep(i,1,n+k)mi[i]=mi[i-1]*2%mo;
	res=mi[n+k];
	sort(e+1,e+m+1,cmp);
	rep(l,1,m){
		int r;for(r=l;r<=m;r++)if(e[r].c!=e[l].c)break;
		//[l,r-1]
		rep(i,l,r-1){
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v){cnt--;f[u]=v;tmp.pb(u);}
		}
		res+=mi[cnt]-mi[n];
		cnt=n;per(i,SZ(tmp)-1,0)f[tmp[i]]=tmp[i];tmp.clear();
		l=r-1;
	}
	cout<<(res%mo+mo)%mo;return 0;
}