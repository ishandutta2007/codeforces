#include<bits/stdc++.h>
using namespace std;
int t,n,a[12345],b[12345];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        long long ans=0;
        for(int l=1;l<=n;++l)for(int r=l;r<=n;++r)
            for(int j=l;j<=r;++j)ans+=a[j]==0,ans++;
        cout<<ans<<endl;
    }
}