#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se seoncd
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=5005,mod=1e9+7;
int f[N][N],a[N],n,K,las=1;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

int main(){
	read(n),read(K);
	rep(i,1,n) read(a[i]),las=(ll)las*a[i]%mod;
	f[0][0]=1;
	rep(i,1,n){
		f[i][0]=(ll)f[i-1][0]*a[i]%mod;
		rep(j,1,i) f[i][j]=((ll)f[i-1][j]*a[i]+mod-f[i-1][j-1])%mod;
	}
	int prod=1,ans=0;
	per(i,K,max(0,K-n)){
		ans=(ans+(ll)prod*f[n][K-i]%mod*power(n,i))%mod;
		prod=(ll)prod*i%mod;
	}
	ans=(mod+las-(ll)ans*power(power(n,mod-2),K)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}