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
const int N = 555555;
int n,a[N],q,mx;
Pii ans[N];int t;
int main() {
	read(n);read(q);rep(i,1,n)read(a[i]),umax(mx,a[i]);
	int f=1,r=n;
	while(1){
		ans[++t]=Pii(a[f],a[f+1]);
		if(a[f]<a[f+1])a[++r]=a[f],f++;
		else a[++r]=a[f+1],a[f+1]=a[f],f++;
		if(a[f]==mx)break;
	}
//	rep(i,1,n)printf("%d ",a[f+i-1]);printf("-->%d\n",t);
	while(q--){
		ll x;read(x);
		if(x<=t)printf("%d %d\n",ans[x].fi,ans[x].se);
		else{
			printf("%d %d\n",mx,a[f+(x-1-t)%(n-1)+1]);
		}
	}
	return 0;
}