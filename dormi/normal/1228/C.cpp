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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli mod=1e9+7;
lli fastpow(lli a,lli b){
	lli ans=1;
	for(lli i=1;i<=b;i<<=1){
		if(i&b){
			ans=ans*a%mod;
		}
		a=(a*a)%mod;
	}
	return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli x,n;
	sc(x,n);
	vector<pll> factors;
	for(lli i=2;i<=sqrt(x);i++){
		lli cnt=0;
		while(x%i==0){
			cnt+=1;
			x/=i;
		}
		if(cnt){
			factors.push_back({i,cnt});
		}
	}
	if(x!=1)factors.push_back({x,1});
	lli ans=1;
	for(pll x:factors){
		lli cur=x.first;
		while(cur<=n/x.first){
			lli pows=n/cur;
			ans=(ans*fastpow(cur%mod,pows-pows/x.first))%mod;
			cur*=x.first;
		}
		if(cur<=n){
			lli pows=n/cur;
			ans=(ans*fastpow(cur%mod,pows-pows/x.first))%mod;
		}
	}
	prl(ans);
    return 0;
}