#include<bits/stdc++.h>
using namespace std;
int n,m,t; long long a[233333],x;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i) a[i]=0;
        for(int i=1;i<=n;++i) for(int j=0;j<m;++j) scanf("%lld",&x), a[i]+=j*x;
        if(a[1]!=a[2]){if(a[3]==a[1]) cout<<"2 "<<a[2]-a[1]<<endl; else cout<<"1 "<<a[1]-a[2]<<endl;}
        else for(int i=3;i<=n;++i) if(a[i]!=a[1]) cout<<i<<' '<<a[i]-a[1]<<endl;
    }
}