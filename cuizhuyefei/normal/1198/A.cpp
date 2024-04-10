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
const int N = 666666;
int n,q,a[N],Log[N],s[N],qz[N],len;
int main() {
	read(n);read(q);q*=8;
	rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n){
		int j=i;for(;j<=n;j++)if(a[i]!=a[j])break;
		//[i,j-1]
		s[++len]=j-i;i=j-1;
	}
	rep(i,1,n){
		while((1<<Log[i])<i)Log[i]++;
	}
	int mx=0,res=n;
	rep(i,1,len)if(n*Log[i]<=q)mx=i;
	rep(i,1,len)qz[i]=qz[i-1]+s[i];
	rep(i,1,len-mx+1)umin(res,n-(qz[i+mx-1]-qz[i-1]));
	printf("%d\n",res);
	return 0;
}