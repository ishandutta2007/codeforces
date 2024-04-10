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
void GG(){puts("NO"); exit(0); }
int main(){
	int n; scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int> > q;
	vector<int> ans(n);
	vector<pair<int,int> > q1(n+n);
	for(int i=0;i<2*n;++i){
		char s[5]; scanf("%s",s);
		if(s[0]=='+') q1[i].first=1;
		else{
			q1[i].first=0;
			scanf("%d",&q1[i].second);
		}
	}
	reverse(q1.begin(),q1.end());
	int pos=n-1;
	for(auto t:q1){
//		printf("[%d %d]\n",t.first,t.second);
		if(t.first==0){
			if(!q.empty()&&t.second>q.top())
				GG();
			q.push(t.second);
//			ans[pos--]=t.second;
		}else{
			if(q.empty()) GG();
			ans[pos--]=q.top();
			q.pop();
		}
	}
	puts("YES");
	for(auto x:ans) printf("%d ",x);
	return 0;
}