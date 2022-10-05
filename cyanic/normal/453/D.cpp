#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
#define ALL(x) (x).begin(),(x).end()
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

const int N=(1<<20)+5;
ll f[N],g[N],b[25],n,mod,t;

ll fix(ll x){
	return x>=mod?x-mod:x;
}
ll power(ll x,ll p){
	ll res=1;
	for(;p;p>>=1,x=(__int128)x*x%mod)
		if(p&1) res=(__int128)res*x%mod;
	return res;
}

void fwt(ll *a,int n){
	for(int k=0,d=1;k<n;k++,d<<=1){
		for(int i=0;i<(1<<n);i+=d<<1){
			ll *l=a+i,*r=a+i+d;
			for(int j=0;j<d;j++,l++,r++){
				ll t=*r;
				*r=fix(*l+mod-t);
				*l=fix(*l+t);
			}
		}
	}
}

int main(){
	read(n),read(t),read(mod);
	mod<<=n;
	REP(i,1<<n) read(f[i]);
	rep(i,0,n) read(b[i]);
	REP(i,1<<n) g[i]=b[__builtin_popcount(i)];
	fwt(f,n),fwt(g,n);
	REP(i,1<<n){
		f[i]=(__int128)f[i]*power(g[i],t)%mod;
	}
	fwt(f,n);
	REP(i,1<<n){
		f[i]=((f[i]%mod+mod)%mod)>>n;
		printf("%lld\n",f[i]);
	}
	return 0;
}