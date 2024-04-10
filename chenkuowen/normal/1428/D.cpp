#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){for(auto t:y)t<x?x=t:0;}
template<class T> inline void dmax(T& x,vector<T> y){for(auto t:y)t>x?x=t:0;}
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int N=5+1e6;
int a[N],top;
vector<pair<int,int> > ans;
vector<vector<int> > p1,p2;
void opera(vector<int> p){
	reverse(p.begin(),p.end());
//	for(auto x:p) printf("[%d]",x); puts("");
	ans.push_back(make_pair(top,p[0]));
	for(int i=0;i<p.size();++i){
		if(a[p[i]]==3){
			ans.push_back(make_pair(top,p[i+1]));
			ans.push_back(make_pair(top-1,p[i+1]));
		}else if(a[p[i]]==2){
			ans.push_back(make_pair(top,p[i+1]));
		}
		--top;
	}
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	top=n;
	for(int i=n;i>=1;--i){
		if(a[i]==1){
			p1.push_back(vector<int>({i}));
		}else if(a[i]==2){
			if(p1.empty()){
				puts("-1");
				exit(0);
			}else{
				p2.push_back(p1.back());
				p1.pop_back();
				p2[(int)p2.size()-1].push_back(i);
			}
		}else if(a[i]==3){
			if(!p2.empty()){
				p2[(int)p2.size()-1].push_back(i);
			}else if(!p1.empty()){
				p2.push_back(p1.back());
				p1.pop_back();
				p2[(int)p2.size()-1].push_back(i);
			}else{
				puts("-1");
				exit(0);
			}
		}
	}
	for(auto x:p1) opera(x);
	for(auto x:p2) opera(x);
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d\n",n-x.first+1,x.second);
	return 0;
}