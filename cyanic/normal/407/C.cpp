#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005,M=105,mod=1e9+7;
int fac[N],rev[N],f[N][M],a[N],n,m,l,r,k;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1) res=(ll)res*x%mod;
	return res;
}

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

void init(int n){
	fac[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=power(fac[n],mod-2);
	per(i,n,1) rev[i-1]=(ll)rev[i]*i%mod;
}

int C(int n,int m){
	return m<0||m>n?0:(ll)fac[n]*rev[m]%mod*rev[n-m]%mod;
}

int main(){
	read(n),read(m),init(n+100);
	rep(i,1,n) read(a[i]);
	while(m--){
		read(l),read(r),read(k);
		rep(i,0,k){
			add(f[l][i],C(k,k-i));
			add(f[r+1][i],mod-C(k+r-l+1,k-i));
		}
	}
	rep(i,1,n){
		rep(j,0,100){
			add(f[i+1][j],f[i][j]);
			if(j) add(f[i+1][j-1],f[i][j]);
		}
		add(a[i],f[i][0]);
	}
	rep(i,1,n){
		printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}