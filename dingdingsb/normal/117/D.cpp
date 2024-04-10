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
ll n,m,mod;
#define mul(x,y) ((x)%mod)*((y)%mod)%mod
#define add(x,y) ((x)+(y))%mod
ll get(ll fs,ll num,ll lim,ll d){
	if(lim<fs)return 0;
	lim=(lim-fs)/d*d+fs;
	ll ls=min(lim,fs+d*(num-1));
	ll v1=(ls-fs)/d+1,v2=(fs+ls);
	if(v1%2==0)v1/=2;
	else v2/=2;
	return mul(v1,v2);
}
ll solve(ll lim,ll fs,ll d,ll num,ll len){
	if(num==0)return 0;
	if(len==1)return fs<=lim?fs:0;
	ll mid=(len+1)/2;
	if(num>=mid)return add(get(fs,mid,lim,d*2),solve(lim,fs+d,d*2,num-mid,len-mid));
	else return solve(lim,fs,d*2,num,mid);
}
signed main(){
	read(n,m,mod);
	while(m--){
		ll l,r,x,y;
		read(l,r,x,y);
		write((((solve(y,1,1,r,n)-solve(x-1,1,1,r,n)+mod)%mod-(solve(y,1,1,l-1,n)-solve(x-1,1,1,l-1,n)+mod)%mod)+mod)%mod);
		putchar('\n');
	}
}