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
const int N = 433333;
int n,q,a[N],hz[18][N];char S[N];
int main() {
	read(n);scanf("%s",S);
	rep(i,0,n-1)a[i]=S[i]-'0';
	per(i,n-1,1)a[i]^=a[i-1];
	rep(j,0,17)per(i,n-1,0)hz[j][i]=a[i]+(i+(1<<j)<n?hz[j][i+(1<<j)]:0);
	int q;read(q);
	while(q--){
		int l,r;read(l);read(r);
		int res=0;
		for(int k=1;l+(1<<k-1)<=r;k++){
			int cnt=(r-l+1)>>k,t=hz[k][l+(1<<k-1)]-(r+1+(1<<k-1)<n?hz[k][r+1+(1<<k-1)]:0);
			res+=min(t,cnt-t);
		}
		printf("%d\n",(res+1)>>1);
	}
	return 0;
}