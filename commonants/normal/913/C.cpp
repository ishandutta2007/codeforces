#include<bits/stdc++.h>

using namespace std;

int n,L;
long long a[33];
int main(){
    cin>>n>>L;
    for(int i=0;i<n;i++)cin>>a[i];
    while(n<31)a[n++]=1ll<<60;
    for(int i=1;i<n;i++)a[i]=min(a[i],a[i-1]<<1);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=((L>>i)&1)*a[i];
    }
    for(int i=0;i<n;i++)if(!((L>>i)&1)){
        long long tans=a[i];
        for(int j=i+1;j<n;j++)tans+=((L>>j)&1)*a[j];
        ans=min(ans,tans);
    }
    cout<<ans<<endl;
    return 0;
}