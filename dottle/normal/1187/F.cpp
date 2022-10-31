#include<bits/stdc++.h>
#define int long long
const int N=200500,mod=1e9+7;
using namespace std;


int l[N],r[N];
int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}
int calc(int k){
	int L=min(r[k],r[k+1])-max(l[k],l[k+1])+1;L=max(L,0ll);
	return L*inv(r[k]-l[k]+1)%mod*inv(r[k+1]-l[k+1]+1)%mod;
}
int ncalc(int k){
	return mod+1-calc(k);
}
int calc1(int k){
	int ans=1-calc(k)-calc(k+1);
	int L=min(min(r[k],r[k+1]),r[k+2])-max(max(l[k],l[k+1]),l[k+2])+1;L=max(L,0ll);
	return ans+L*inv(r[k]-l[k]+1)%mod*inv(r[k+1]-l[k+1]+1)%mod*inv(r[k+2]-l[k+2]+1)%mod;
}

main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	for(int i=1;i<=n;i++)cin>>r[i];
	int ans=1,s=0;
	for(int i=1;i<n;i++)
		s+=ncalc(i),ans-=ncalc(i)*ncalc(i)%mod;s%=mod;
	ans+=s*(s+3)%mod;
	for(int i=1;i<n-1;i++)
		ans-=ncalc(i)*2*ncalc(i+1)%mod;
	for(int i=1;i<n-1;i++)
		ans+=2*calc1(i);
	cout<<(ans%mod+mod)%mod;
}