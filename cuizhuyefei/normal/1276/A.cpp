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
const int N = 666666,inf=0x3f3f3f3f;
int n;char s[N];
Pii f[N][6];
int trans(int x, char c){//0..4 5
	if(x==1){if(c=='n')return 2;x=0;}
	else if(x==2){if(c=='e')return 5;x=0;}
	else if(x==3){if(c=='w')return 4;x=0;}
	else if(x==4){if(c=='o')return 5;x=0;}
	if(c=='o')return 1;if(c=='t')return 3;return 0;
}
void upd(Pii &a, Pii b){if(b.fi<a.fi)a=b;}
int main() {//freopen("1.in","r",stdin);
	int T;read(T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,0,n)rep(j,0,5)f[i][j]=Pii(inf,-1);
		f[0][0]=Pii(0,0);
		rep(i,0,n-1)rep(j,0,4)if(f[i][j].fi<inf){
			upd(f[i+1][j],Pii(f[i][j].fi+1,inf));
			if(trans(j,s[i+1])<=4)upd(f[i+1][trans(j,s[i+1])],Pii(f[i][j].fi,j));
		}
		Vi a;int b=0;rep(c,0,4)if(f[n][c].fi<=f[n][b].fi)b=c;
		int tot=f[n][b].fi;
		for(int i=n,j=b;i>=1;i--){
			if(f[i][j].se==inf)a.pb(i);else j=f[i][j].se;
		}
		assert(SZ(a)==tot);
		printf("%d\n",tot);rep(i,0,SZ(a)-1)printf("%d ",a[i]);puts("");
	}
	return 0;
}