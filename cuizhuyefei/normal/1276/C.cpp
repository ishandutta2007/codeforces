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
const int N = 1020000;
int n,a[N];Pii b[N],f[N];int sz,A,B,s[N];
vector<Vi>ans;bool vis[N];
int main() {
	read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n){
		int j=i;while(j+1<=n&&a[j+1]==a[i])j++;
		b[++sz]=Pii(j-i+1,a[i]);i=j;
	}
	sort(b+1,b+sz+1);A=1;B=1;
	for(int i=1,j=0,tot=0;i<=n;i++){
		while(j+1<=sz&&b[j+1].fi<=i)j++,tot+=b[j].fi;
		int k=(tot+i*(sz-j))/i;if(k>=i&&i*k>A*B)A=i,B=k;
	}
	if(A>B)swap(A,B);
	ans.resize(A+1);rep(i,1,A)ans[i].resize(B+1);
	reverse(b+1,b+sz+1);
	int len=0;rep(i,1,sz){
		for(int j=1;j<=min(A,b[i].fi)&&len<A*B;j++)s[++len]=b[i].se;//s[i]<N
	}
	for(int i=1,x=1,y=1;i<=len;i++){
		ans[x][y<=B?y:y-B]=s[i];
		x++;y++;if(x>A){x=1;y=i/A+1;}
	}
	printf("%d\n%d %d\n",A*B,A,B);
	rep(i,1,A){rep(j,1,B)printf("%d ",ans[i][j]);puts("");}
	return 0;
}