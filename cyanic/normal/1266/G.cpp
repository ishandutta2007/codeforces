#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=1e6+5,mod=998244353;
int fac[N],rev[N],n,p,ans;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

int main(){
	read(n),fac[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=power(fac[n],mod-2);
	per(i,n,1) rev[i-1]=(ll)rev[i]*i%mod;
	p=(ll)fac[n]*n%mod;
	ans=(ll)p*(p+1)/2%mod;
	rep(i,0,n-1){
		int c=(i==0?n:(ll)fac[n]*rev[n-i+1]%mod
					*((ll)(n-i)*(n-i)%mod+1)%mod);
		ans=(ans+mod-(ll)c*i%mod)%mod;
		c=(mod+fac[n]-c)%mod;
		ans=(ans+mod-(ll)c*(n+i)%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}