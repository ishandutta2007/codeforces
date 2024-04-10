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
typedef pair<ll,int> Pli;
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
const int N = 266666;
int n,m,k,p,h[N],a[N];ll val[N],cnt[N],need[N];
priority_queue<Pli,vector<Pli>,greater<Pli> >heap;
inline ll ck(ll mid){
	ll tot=0;
	rep(i,1,n){
		ll x=h[i]-(mid-1LL*m*a[i]);
		if(x<=0)need[i]=0;
		else need[i]=(x+p-1)/p;
		tot+=need[i];
	}
	if(tot>m*k)return 0;
	rep(i,1,n)val[i]=mid,cnt[i]=0;
	while(!heap.empty())heap.pop();
	rep(i,1,n)if(cnt[i]<need[i])heap.push(Pli((mid+cnt[i]*p)/a[i],i));
	rep(j,1,m){
		rep(tt,1,k)if(!heap.empty()){
			int u=heap.top().se;if(heap.top().fi<j)return 0;heap.pop();
			cnt[u]++;val[u]+=p;
			if(cnt[u]<need[u])heap.push(Pli((mid+cnt[u]*p)/a[u],u));
		}
	}
	return 1;
}
int main() {//freopen("1.in","r",stdin);
	read(n);read(m);read(k);read(p);
	rep(i,1,n)read(h[i]),read(a[i]);
	ll l=0,r=1e13;
	while(l<r){
		ll mid=(l+r)>>1;
		if(ck(mid))r=mid;else l=mid+1;
	}
	cout<<l;
	return 0;
}