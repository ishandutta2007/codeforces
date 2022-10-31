#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;

int k;
int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

main(){
	ios::sync_with_stdio(false);
	cin>>k;
	cout<<6*gsc(4,(1ll<<k)-2)%mod;
}