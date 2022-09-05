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
int n,k,a[N],qz[N];char T[N];
int pre[N][2],nxt[N][2];
bool ck(int l, int r, int x){
	int L=nxt[1][x^1],R=pre[n][x^1];
	if(L>=l&&L<=r)L=nxt[r+1][x^1];
	if(R>=l&&R<=r)R=pre[l-1][x^1];
	return R-L+1<=k;
}
int main() {
	read(n);read(k);scanf("%s",T+1);
	rep(i,1,n)a[i]=T[i]-'0',qz[i]=qz[i-1]+a[i];
	rep(i,1,n-k+1)if(qz[n]-(qz[i+k-1]-qz[i-1])+k==n){
		puts("tokitsukaze");return 0;
	}
	rep(i,1,n-k+1)if(qz[n]-(qz[i+k-1]-qz[i-1])==0){
		puts("tokitsukaze");return 0;
	}
	rep(i,1,n){//1..i
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		pre[i][a[i]]=i;
	}
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	per(i,n,1){
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][a[i]]=i;
	}
	bool bwin=1;
	rep(i,1,n-k+1){
		//[i..i+k-1] --> 1
		bwin&=ck(i,i+k-1,1);
		bwin&=ck(i,i+k-1,0);
	}
	if(bwin)puts("quailty");else puts("once again");
	return 0;
}