#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010,mod=1e9+7;
int i,j,k,n,m,y,e;
long long ans=1,a[maxn];
int main(){
    a[0]=1;a[1]=1;
	cin>>n;
    for(i=2;i<=n;i++)a[i]=(a[i-2]*(i-1)+a[i-1])%mod;
    for(i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if(x==1)y++;else e++;
    }
    for(i=n;e;i--,e--){
        ans*=i;
        ans%=mod;
    }cout<<ans*a[y]%mod<<endl;
}