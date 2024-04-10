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
const int N = 505000;
int n,m,a[N],b[N];
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);a[++n]=1e9;
	int tot=0;rep(i,1,m){
		int x1,x2,y;read(x1);read(x2);read(y);
		if(x1==1)b[++tot]=x2;
	}
	m=tot;sort(a+1,a+n+1);sort(b+1,b+m+1);int res=1e9;
	for(int i=n,j=m+1;i>=1;i--){
		while(j-1>=1&&b[j-1]>=a[i])j--;
		umin(res,i-1+m-j+1);
	}
	cout<<res;
	return 0;
}