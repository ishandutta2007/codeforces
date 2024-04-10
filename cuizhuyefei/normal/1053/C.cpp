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
const int N = 444444, mo = 1e9+7;
int n,q,a[N],w[N];ll v1[N],v2[N],v3[N];
void add(int p, ll v){v3[0]+=v;while(p<=n)v3[p]+=v,p+=p&-p;}
ll query(int p){ll res=0;while(p)res+=v3[p],p-=p&-p;return res;}
inline void add(ll *a, int p, ll v){
	a[0]=(a[0]+v)%mo;while(p<=n)a[p]=(a[p]+v)%mo,p+=p&-p;
}
inline ll query(ll *a, int p){ll res=0;while(p)res+=a[p],p-=p&-p;return res%mo;}
ll getval(ll *a, int l, int r){
	l=max(l,1);r=min(r,n);
	if(l>r)return 0;if(l==1)return query(a,r);return (a[0]-query(a,l-1)+mo)%mo;
}
//ll getans(int p,int u, int v,int l){return (1LL*p*getval(v2,1,u)-getval(v1,1,u)+getval(v1,v,n)-1LL*(p+l)*getval(v2,v,n))%mo;}
ll getans(int x, int p){
	return (query(v1,x)+1LL*query(v2,x)*(a[p]-p))%mo;
}
int main() {
	read(n);read(q);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(w[i]),add(v1,i,1LL*(i-a[i])*w[i]%mo),add(v2,i,w[i]),add(i,w[i]);
	while(q--){
		int u,v;read(u);read(v);
		if(u<0){u=-u;add(v1,u,1LL*(u-a[u])*(v-w[u]+mo)%mo);add(v2,u,v-w[u]);add(u,v-w[u]);w[u]=v;}
		else{
			/*int l=v-u,L=a[1],R=a[n],p1,p2;
			while(L<=R){
				int mid=(L+R)>>1;
				ll left=query(lower_bound(a+1,a+n+1,mid)-1-a);
				ll right=v3[0]-query(upper_bound(a+1,a+n+1,mid+l)-a-1);//WA
				if(left==right){p1=p2=mid;break;}
				if(left>right){p2=mid;R=mid-1;}
				else {p1=mid;L=mid+1;}
			}
			int u1=lower_bound(a+1,a+n+1,p1)-1-a,v1=upper_bound(a+1,a+n+1,p1+l)-a;
			int u2=lower_bound(a+1,a+n+1,p2)-1-a,v2=upper_bound(a+1,a+n+1,p2+l)-a;
			ll res;
			if(p1==p2||query(u2)>v3[0]-query(v1-1))
				res=getans(p1,u1,v1,l);
			else res=getans(p2,u2,v2,l);*/
		//	u=lower_bound(a+1,a+n+1,p)-1-a;v=upper_bound(a+1,a+n+1,p+l)-a;
		//	ll res=1LL*p*getval(v2,1,u)-getval(v1,1,u)+getval(v1,v,n)-1LL*(p+l)*getval(v2,v,n);
			int l=u,r=v,p=l,L=l,R=r;//WA
			while(L<=R){
				int mid=(L+R)>>1;ll x=query(mid)-query(l-1)-(query(r)-query(mid));
				if(x==0){p=mid;break;}
				if(x<0)p=mid;
				if(x>0)R=mid-1;else L=mid+1;
			}
			if(p+1<=r&&query(p)-query(l-1)<query(r)-query(p))p++;
		//	printf(" p = %d\n",p);
			ll res=getans(p-1,p)-getans(l-1,p)-(getans(r,p)-getans(p,p));
			printf("%lld\n",(res%mo+mo)%mo);
		}
	}
	return 0;
}