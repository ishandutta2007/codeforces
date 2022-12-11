#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,mod=1e9+7;
int n,a[N],T,k,pw[N],ans;
int main(){
    scanf("%d",&n);pw[0]=1;
    for(int i=1;i<=n;i++)pw[i]=2*pw[i-1]%mod;
    for(int i=1,x;i<=n;i++)scanf("%d",&x),~x?a[x]++:0;
    for(int i=1;i<=n;i++)(ans+=pw[a[i]]-1)%=mod;
    cout<<(pw[n-1]-1-ans+mod)%mod;
    return 0;
}