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
const int N = 505000,M=72;
int q,n=1,fa[N];double f[N][M+2];
void init(int x){
	rep(i,0,M)f[x][i]=1;
}
int main() {
	read(q);init(1);
	while(q--){
		int op,u;read(op);read(u);
		if(op==1){
			++n;fa[n]=u;init(n);//f[u][0]*=0.5;
			static int sta[N];int top=0;
			for(int i=u;i&&top<=M;i=fa[i])sta[++top]=i;
			per(i,top,2)f[sta[i]][i-1]/=0.5+0.5*f[sta[i-1]][i-2];
			f[sta[1]][0]*=0.5;
			rep(i,2,top)f[sta[i]][i-1]*=0.5+0.5*f[sta[i-1]][i-2];
		}
		else{
			double res=0;
			rep(i,1,M)res+=i*(f[u][i]-f[u][i-1]);
		//	rep(i,0,4)printf("%d:%lf\n",i,f[1][i]);
			printf("%.10lf\n",res);
		}
	}
	return 0;
}