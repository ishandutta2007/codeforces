#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
ll k,p;
const ll mod=1e9+7;
ll fpow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}
signed main(){
	read(p,k);
	if(k==0)write(fpow(p,p-1)),exit(0);
	if(k==1)write(fpow(p,p)),exit(0);
	int m=1;ll x=k;
	while(x!=1)
		m++,x=x*k%p;
	write(fpow(p,(p-1)/m));
}