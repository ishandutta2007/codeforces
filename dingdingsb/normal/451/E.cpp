#include<bits/stdc++.h>
#define int long long
int k,r,n[40];
int inv[40];
const int mod=1000000007;
int pow(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ret;
}
int C(int y,int x){
    if (y<0||x<0||y<x) return 0;
    y%=mod;
    if (y==0 || x==0) return 1;
    int ans=1;
    for (int i=0;i<x;i++)
        ans=ans*(y-i)%mod;
    for (int i=1;i<=x;i++)
        ans=ans*inv[i]%mod;
    return ans;
}
signed main(){
	inv[1]=1;
    for(int i=2;i<40;i++)
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	std::cin>>k>>r;
	for(int i=1;i<=k;i++)
		std::cin>>n[i];
	int ans=C(k+r-1,k-1);
	for(int S=1;S<(1<<k);S++){
		//
		int tmp=k+r,num=0;
        for(int i=0;i<k;i++)
            if((S>>i)&1)
				num++,tmp-=n[i+1];
        tmp-=num+1;
        if(num%2)ans=(ans-C(tmp,k-1))%mod;
        else ans=(ans+C(tmp,k-1))%mod; 
        //printf("%d %d %d\n",num,tmp,ans);
	}
	std::cout<<(ans+mod)%mod;
	return 0;
}