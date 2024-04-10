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
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000;
ll n,m,t,p[N],val[N],res;
Pii ck(ll d){//used up; val
	ll now=0,val=0,lst=0,lstval=0;bool ok=1;
	rep(i,1,n)if(p[i]<=d){
		if(now+p[i]>t){ok=0;break;}
		now+=p[i];val++;lst++;lstval+=p[i];
		if(lst==m)lst=0,now+=lstval,lstval=0;
	}
	return Pii(ok,val);
}
int main() {//freopen("1.in","r",stdin);
	ll T;read(T);
	while(T--){
		read(n);read(m);read(t);rep(i,1,n)read(p[i]);
		ll len=0;rep(i,1,n)val[++len]=p[i];
		sort(val+1,val+len+1);len=unique(val+1,val+len+1)-val-1;res=0;
		ll L=1,R=len,d=0;
		while(L<=R){
			ll mid=(L+R)>>1;
			if(ck(val[mid]).fi)d=mid,L=mid+1;else R=mid-1;
		}
		ll a=ck(val[d]).se,b=d+1<=len?ck(val[d+1]).se:-1;
		if(a>b)res=a;else res=b,d++;d=val[d];d=min(d,t);
		printf("%lld %lld\n",res,d);
	}
	return 0;
}