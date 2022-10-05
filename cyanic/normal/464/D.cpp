#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005,M=1005;
const double eps=1e-20;
long double f[2][M],g[2][M],fac[N],ans;
int n,K;

void dp(int i){
	memset(f[i],0,sizeof f[i]);
	memset(g[i],0,sizeof g[i]);
	rep(j,1,1000)
		if(g[i^1][j]>eps){
			g[i][j]+=g[i^1][j]*j/(j+1);
			g[i][j+1]+=g[i^1][j]/(j+1);
			f[i][j]+=(f[i^1][j]+g[i^1][j]*(j+1)*0.5)*j/(j+1);
			f[i][j+1]+=(f[i^1][j]+g[i^1][j]*(j+1))/(j+1);
		}
}

int main(){
	read(n),read(K);
	fac[0]=0;
	rep(i,1,n)fac[i]=fac[i-1]+logl(i);
	int cur=0;f[0][1]=g[0][1]=1;
	rep(i,1,n){
		dp(cur^=1);
		long double res=0;
		rep(j,1,1000){
			res+=f[cur][j]-j*g[cur][j];
			//if(j<=2)printf("# %d  %.2lf %.2lf\n",j,f[i][j],g[i][j]);
		}
		//printf("%d %.2lf\n",i,res);
		long double coef=fac[n]-fac[i]-fac[n-i];
		if(K==1)coef=0;
		else coef+=logl(K-1)*(n-i)-logl(K)*n;
		if(K!=1||i==n)ans+=K*res*expl(coef);
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}