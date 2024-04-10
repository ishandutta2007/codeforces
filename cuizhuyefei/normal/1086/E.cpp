#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2030,mo=998244353;
int n,fac[N],ifac[N],C[N][N],f[N][N],a[N][N];
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
void add(int &x, int y){x=(x+y)%mo;}
int v1[N],v2[N];
void add(int *v, int p, int x){if(p)while(p<=n)v[p]+=x,p+=p&-p;}
int query(int *v, int p){int r=0;while(p>0)r+=v[p],p-=p&-p;return r;}
int solve(int *a, int *b){//<a ban b
	memset(v1,0,sizeof(v1));memset(v2,0,sizeof(v2));
	if(b[1]==0){
		rep(i,1,n)add(v1,i,1);int res=0;
		rep(i,1,n)res=(res+1LL*query(v1,a[i]-1)*fac[n-i])%mo,add(v1,a[i],-1);
		return res;
	}
	static int buc[N],match[N],gg[N];
	rep(i,1,n)buc[b[i]]=i;
	rep(i,1,n)match[i]=buc[a[i]];
	rep(i,1,n)gg[i]=0;//b[i] is gg
	int res=0;add(v1,b[1],1);rep(i,2,n)add(v2,b[i],1);
	rep(i,1,n){
		int x=query(v1,a[i]-1),y=query(v2,a[i]-1);
		if(!gg[i]&&b[i]<a[i])x--;
		res=(res+1LL*x*f[n-i][query(v2,n)]+(y?1LL*y*f[n-i][query(v2,n)-1]:0))%mo;
		if(a[i]==b[i])break;
		gg[match[i]]=1;
		if(match[i]<=i)add(v1,b[match[i]],-1);else add(v2,b[match[i]],-1);
		if(!gg[i+1]){
			add(v2,b[i+1],-1);add(v1,b[i+1],1);
		}
	}
	/*puts("");
	rep(i,1,n)printf("%d ",a[i]);puts("");
	rep(i,1,n)printf("%d ",b[i]);puts("");
	printf("res=%d\n",res);*/
	return res;
}
int main() {
	read(n);
	fac[0]=1;rep(i,1,n)fac[i]=1LL*i*fac[i-1]%mo;
	ifac[n]=power(fac[n],mo-2);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	rep(i,0,n){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	rep(i,0,n)rep(j,0,i){
		if(i<=1||j<=1)rep(k,0,j)add(f[i][j],1LL*(k&1?mo-1:1)*C[j][k]%mo*fac[i-k]%mo);
		else f[i][j]=(f[i][j-1]-f[i-1][j-1]+mo)%mo;
		//printf("%d %d:%d\n",i,j,f[i][j]);
	}
	rep(i,1,n)rep(j,1,n)read(a[i][j]);
	int res=0;
	rep(i,1,n)//<
		res=(res+1LL*solve(a[i],a[i-1])*power(f[n][n],n-i))%mo;
	
	cout<<res;
	return 0;
}