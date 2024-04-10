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

const int N=200005,mod=998244353;
int fac[N],rev[N],a[N];
int n,K,cnt,ans;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
int C(int n,int m){
	return (ll)fac[n]*rev[m]%mod*rev[n-m]%mod;
}
void init(int n){
	fac[0]=1;
	rep(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=power(fac[n],mod-2);
	per(i,n,1)rev[i-1]=(ll)rev[i]*i%mod;
}

int main(){
	read(n),read(K);
	init(n);
	rep(i,1,n){
		read(a[i]);
		if(i>=2&&a[i]!=a[i-1]){
			++cnt;
		}
	}
	if(a[1]!=a[n]){
		++cnt;
	}
	ans=power(K,cnt);
	rep(i,0,cnt/2){
		ans=(ans+mod-mul(power(K-2,cnt-2*i),
					 mul(C(cnt,i),C(cnt-i,i))))%mod;
	}
	ans=mul(ans,(mod+1)/2);
	ans=mul(ans,power(K,n-cnt));
	cout<<ans<<endl;
	return 0;
}