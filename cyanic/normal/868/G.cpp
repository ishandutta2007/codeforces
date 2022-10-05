#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=1e9+7;
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
}

struct fun{
	int k,b;
	fun(int _k=0,int _b=0):k(_k),b(_b){}
	friend fun operator + (fun x,fun y){
		return fun(fix(x.k+y.k),fix(x.b+y.b));
	}
	friend fun operator - (fun x,fun y){
		return fun(fix(x.k+mod-y.k),fix(x.b+mod-y.b));
	}
	friend fun operator * (fun x,fun y){
		return fun(mul(x.k,y.k),fix(mul(x.k,y.b)+x.b));
	}
	friend fun operator ^ (fun x,int y){
		fun res(1,0);
		for(;y;y>>=1,x=x*x) if(y&1)res=res*x;
		return res;
	}
	fun inv(){
		int rev=power(k,mod-2);
		return fun(rev,mul(b,mod-rev));
	}
	//s(x) + s(x^2) + s(x^3) + ... + s(x^y)
	friend pair<fun,fun> calc(fun x,int p){
		if(p==1) return mp(x,x);
		pair<fun,fun> ret=calc(x,p>>1);
		ret.se=ret.se+(ret.se*ret.fi);
		ret.fi=ret.fi*ret.fi;
		if(p&1) ret.fi=ret.fi*x,ret.se=ret.se*x+x;
		return ret;
	}
	friend fun S(fun s,fun x,int y){
		if(y<=0) return fun(0,0);
		fun res=calc(x,y).se;
		res.k=mul(res.k,s.k);
		res.b=mul(res.b,s.k);
		res.b=fix(res.b+mul(s.b,y));
		return res;
	}
	int val(int x){
		return fix(mul(k,x)+b);
	}
};

int solve(int n,int k,fun A,fun B,fun S1,fun S2){
	if(n==1){
		int x=mul(B.b,power(mod+1-B.k,mod-2));
		return S1.val(x);
	}
	int q=(n-1)/k,r=n-q*k;
	fun nA=(A.inv()^(q-1))*(B.inv());
	fun nB=(A.inv()^q)*(B.inv());
	fun nS1=S1+S(S2,A,q);
	fun nS2=S1+S(S2,A,q-1);
	return solve(k,r,nA,nB,nS1,nS2);
}

void rmain(){
	int n,k,g;
	read(n),read(k);
	g=__gcd(n,k),n/=g,k/=g;
	printf("%lld\n",(ll)power(n,mod-2)*
		solve(n,k,fun(1,1),fun((mod+1)/2,1),
				  fun(1,0),fun(1,0))%mod
	);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}