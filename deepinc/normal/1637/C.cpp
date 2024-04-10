#include<bits/stdc++.h>
using namespace std;
int t,n,a[123456];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int flg=1; long long ans=0;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=2;i<n;++i)ans+=a[i]+1>>1,flg&=a[i]==1;
        if(flg)ans=-1;
        if(n==3&&a[2]&1)ans=-1;
        cout<<ans<<endl;
    }
}