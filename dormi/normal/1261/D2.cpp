#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli mod=998244353;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(b&i)ans=a*ans%mod;
		a=a*a%mod;
	}
	return ans;
}
lli fix(lli a){
	if(a<0)a+=mod;
	return a%mod;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    lli k;
    sc(n,k);
    int ans[n];
    rep(i,(lli)0,n)sc(ans[i]);
    lli ten=0;
    rep(i,(lli)0,n){
    	if(ans[i]==ans[(i+1)%n])ten+=1;
    }
    n-=ten;
    lli tot=fastpow(k,n);
    lli half=n/2;
    lli permu=1;
	tot=fix(tot-fastpow(k-2,n));
    for(lli i=1;i<=half;i++){
        permu=(permu*(n-2*(i-1))%mod)*(n-2*(i-1)-1)%mod;
        lli te=fastpow(i,mod-2);
        permu=permu*te%mod;
	    permu=permu*te%mod;
    	tot=fix(tot-(fastpow(k-2,n-2*i)*permu%mod));
    }
	tot=tot*fastpow(2,mod-2)%mod;
    tot=tot*fastpow(k,ten)%mod;
    prl(tot);
    return 0;
}