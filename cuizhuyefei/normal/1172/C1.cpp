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
const int N = 55,mo=998244353;
int n,m,a[N],w[N],f[N][N][N];
int power(int a,int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
		
	return res;
}
void add(int &x,int y){x=x+y<mo?x+y:x+y-mo;}
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(w[i]);
	rep(x,1,n){
		memset(f,0,sizeof(f));f[0][0][0]=1;
		int w1=0,w2=0,tot=0;rep(i,1,n)tot+=w[i];
		rep(i,1,n)if(i!=x){if(a[i]==0)w1+=w[i];else w2+=w[i];}
		rep(t,0,m-1)rep(i,0,t)rep(j,0,t-i){
			int ni=power(tot+j-i+(t-i-j)*(a[x]?1:-1),mo-2);
			add(f[t+1][i][j],1LL*f[t][i][j]*(w[x]+(t-i-j)*(a[x]?1:-1))%mo*ni%mo);
			add(f[t+1][i+1][j],1LL*f[t][i][j]*(w1-i)%mo*ni%mo);
			add(f[t+1][i][j+1],1LL*f[t][i][j]*(w2+j)%mo*ni%mo);
		}
		int res=0;rep(i,0,m)rep(j,0,m-i)res=(res+1LL*f[m][i][j]*(w[x]+(m-i-j)*(a[x]?1:-1)))%mo;
		printf("%d\n",(res%mo+mo)%mo);
	}
	return 0;
}