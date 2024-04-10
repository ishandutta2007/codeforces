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

const int N=250005;
int f[N],g[N],fac[N],rev[N],n,K,mod,ans;

int fix(int x){
	return x>=mod?x-mod:x;
}
int C(int n,int m){
	return (ll)fac[n]*rev[m]%mod*rev[n-m]%mod;
}
int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

int main(){
	read(n),read(K),read(mod);
	fac[0]=1;
	rep(i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=power(fac[n],mod-2);
	per(i,n,1) rev[i-1]=(ll)rev[i]*i%mod;
	ans=power(K,n);
	if(n%2==0){
		f[n]=1; int tot=K;
		while(K--){
			memset(g,0,sizeof g);
			for(int s=n;s;s=(s-1)&n){
				if(!f[s]) continue;
				for(int t=(s-1)&s;t;t=(t-1)&s)
					g[t]=(g[t]+(ll)f[s]*rev[s^t])%mod;
				g[0]=(g[0]+(ll)f[s]*rev[s])%mod;
			}
			swap(f,g);
			ans=(ans+mod-(ll)f[0]*fac[n]%mod*C(tot,K)%mod)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}