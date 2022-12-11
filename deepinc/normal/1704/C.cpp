#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[233333],b[233333];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;++i) scanf("%d",&a[i]);
        sort(a+1,a+1+m);
        for(int i=1;i<m;++i) b[i]=a[i+1]-a[i]-1;
        b[m]=n+a[1]-a[m]-1;
        sort(b+1,b+1+m);
        reverse(b+1,b+1+m);
        int ans=0;
        for(int i=1;i<=m;++i) ans+=b[i]-i-i-i-i+4==1?1:max(0,b[i]-i-i-i-i+3);
        cout<<n-ans<<endl;
    }
}