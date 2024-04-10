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
 
const int N=1505,M=100005,mod=1e9+7;
namespace{
	int fac[M],rev[M];
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int mul(int x,int y){
		return static_cast<ll>(x)*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int C(int n,int m){
		return m<0||m>n?0:mul(fac[n],mul(rev[m],rev[n-m]));
	}
	void init(){
		const int lim=100000;
		fac[0]=1;
		rep(i,1,lim)fac[i]=(ll)fac[i-1]*i%mod;
		rev[lim]=power(fac[lim],mod-2);
		per(i,lim,1)rev[i-1]=(ll)rev[i]*i%mod;
	}
}
int p[N],s[N],f[N][N],g[N][N];
int n,m,K,a,b;

int main(){
	read(n),read(m),init();
	read(a),read(b),read(K);
	a=mul(a,power(b,mod-2));
	int A=1,B=power(mod+1-a,K);
	b=power(mod+1-a,mod-2);
	rep(i,1,m){
		if(!b)B=!(K-i+1);
		p[i]=mul(mul(A,B),C(K,i-1));
		s[i]=fix(s[i-1]+p[i]);
		A=mul(A,a),B=mul(B,b);
	}
	f[0][m]=g[0][m]=1;
	rep(i,1,n){
		int tmp=0;
		rep(j,1,m){
			add(tmp,mul(p[j],fix(g[i-1][m]+mod-g[i-1][j-1])));
			f[i][j]=mul(p[m-j+1],fix(tmp+mod-mul(s[j],g[i-1][m-j])));
			g[i][j]=fix(g[i][j-1]+f[i][j]);
		}
	}
	printf("%d\n",g[n][m]);
	return 0;
}