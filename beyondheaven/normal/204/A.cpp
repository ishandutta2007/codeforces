#include<bits/stdc++.h>
typedef long long LL;

inline LL pow_mod(LL a,LL b)
{
	if(!b)return a?1:0;
	LL res=1;
	for(;b;b>>=1,a=a*a)
	if(b&1)res=res*a;
	return res;
}

inline LL Solve(LL r)
{
	if(!r)return 0;
	LL _r=r;
	int lg=0,t=0;
	while(_r)++lg,t=_r,_r/=10;
	
	#ifdef Dubug
	std::cout<<"t = "<<t<<std::endl;
	#endif
	
	if(lg==1)return r;
	
	LL ans=9;
	for(int i=2;i<lg;++i)
	ans+=9*pow_mod(10,i-2);
	
	for(int i=1;i<t;++i)
	ans+=pow_mod(10,lg-2);
	
	while(r%10!=t)--r;
	ans+=(r-(t*pow_mod(10,lg-1)+t))/10+1;
	
	return ans;
}

int main()
{
	LL l,r;std::cin>>l>>r;
	std::cout<<Solve(r)-Solve(l-1)<<std::endl;
	return 0;
}