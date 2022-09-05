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
const int N = 102000;
int n,c,d,op[N],a[N];ll val[N];
int main() {
	read(n);read(c);read(d);
	rep(i,1,n){read(a[i]);char t[3];scanf("%s",t);op[i]=t[0]=='P';}
	int e;read(e);
	for(int i=n,p0=e,p1=e;i>=1;i--){
		val[i]=1LL*c*(op[i]==0?p1-a[i]:p0-a[i]);
		if(op[i]==0)p0=a[i];else p1=a[i];
	}
	op[0]=-1;ll now=0,res=1LL*d*n;
	per(i,n,1){
		if(op[i]!=op[i-1]){
			umin(res,1LL*d*(i-1)+now+min(val[i],1LL*d));
			now+=val[i];
		}else now+=min(val[i],1LL*d);
	}
	cout<<res;
	return 0;
}