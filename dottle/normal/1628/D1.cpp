#include<bits/stdc++.h>
#define int long long
const int N=1000500,mod=1e9+7;
using namespace std;

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}
int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

void solve(){
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	if(n==m){cout<<n*k%mod<<endl;return;}
	for(int i=1;i<=m;i++)
		ans+=i*C(n-i-1,m-i)%mod*gsc(inv(2),n-i)%mod;
	cout<<ans%mod*k%mod<<endl;
}

main(){
	init();
	int _T=1;cin>>_T;
	while(_T--)solve();
}