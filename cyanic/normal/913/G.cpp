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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

ll mul(ll a,ll b,ll mod){
	return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}

ll power(ll x,ll p,ll mod){
	ll res=1;
	for(;p;p>>=1,x=mul(x,x,mod))
		if(p&1)res=mul(res,x,mod);
	return res;
}

void rmain(){
	ll a; cin>>a;
	int n=to_string(a).size();
	for(int m=0;;m++){
		ll b=(-a)%(1ll<<(n+m));
		if(b<0) b+=1ll<<(n+m);
		if((a+b)%5==0) b+=1ll<<(n+m);
		if(b==0&&m==0||to_string(b).size()<=m){
			ll c=(a+b)>>(n+m),pw5=5;
			ll t=vi{-1,0,1,3,2}[c%5];
			rep(i,1,n+m-1){
				while(power(2,t,pw5*5)!=c%(pw5*5))
					t+=pw5/5*4;
				pw5*=5;
			}
			cout<<t+n+m<<endl;
			return;
		}
		a*=10;
	}
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}