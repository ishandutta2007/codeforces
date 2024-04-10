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
typedef unsigned long long ull;
typedef pair<ull,ull> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ull R() {
	static unsigned int seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n,m,l[N],r[N],vis[N];Pii v[N],qz[N],s1[N],s2[N],all;
map<Pii,ll>cnt,val;ll res;
int main() {//freopen("1.in","r",stdin);
	read(m);read(n);rep(i,1,m)read(l[i]),read(r[i]);
	rep(i,1,m)v[i].fi=R()*R(),v[i].se=R()*R(),all.fi^=v[i].fi,all.se^=v[i].se;
//	rep(i,1,m)if(i%(m/15)==0)printf("%lld %lld\n",v[i].fi,v[i].se);
	rep(i,1,m){
		qz[l[i]].fi^=v[i].fi,qz[l[i]].se^=v[i].se;
		qz[r[i]+1].fi^=v[i].fi,qz[r[i]+1].se^=v[i].se;		
	}
	rep(i,1,n)qz[i].fi^=qz[i-1].fi,qz[i].se^=qz[i-1].se;
	rep(i,1,n)qz[i].fi^=qz[i-1].fi,qz[i].se^=qz[i-1].se;
	rep(i,1,m){
		s1[1].fi^=v[i].fi,s1[1].se^=v[i].se;
		s1[r[i]+1].fi^=v[i].fi,s1[r[i]+1].se^=v[i].se;
	}
	rep(i,1,n)s1[i].fi^=s1[i-1].fi,s1[i].se^=s1[i-1].se;
	rep(i,1,m){
		s2[l[i]].fi^=v[i].fi,s2[l[i]].se^=v[i].se;
	}
	rep(i,1,n)s2[i].fi^=s2[i-1].fi,s2[i].se^=s2[i-1].se;
	rep(i,1,n){
		cnt[Pii(qz[i-1].fi^s1[i].fi,qz[i-1].se^s1[i].se)]++;
		val[Pii(qz[i-1].fi^s1[i].fi,qz[i-1].se^s1[i].se)]+=i;
		res+=cnt[Pii(all.fi^s2[i].fi^qz[i].fi,all.se^s2[i].se^qz[i].se)]*(i+1);
		res-=val[Pii(all.fi^s2[i].fi^qz[i].fi,all.se^s2[i].se^qz[i].se)];
	}
	rep(i,1,m)vis[l[i]]++,vis[r[i]+1]--;
	rep(i,1,n)vis[i]+=vis[i-1];
	rep(i,1,n)if(!vis[i]){
		int j;for(j=i;j<=n;j++)if(vis[j])break;
		//[i,j-1]
		rep(k,1,j-i)res-=1LL*k*(j-i-k+1);
		i=j-1;
	}
	printf("%lld",res);
	return 0;
}