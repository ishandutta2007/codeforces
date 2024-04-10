#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;

int t,n,mx,sc,cnt;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

void up(int x){
	if(x==sc)cnt++;
	else if(x>sc)sc=x,cnt=1;
}

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		mx=sc=-1;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			if(x>=mx)up(mx),mx=x;
			else up(x);
		}
		int ans=abs(sc-mx)<=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		if(mx!=sc)ans=ans*cnt%mod*inv(cnt+1)%mod;
		cout<<ans<<endl;
	}
}