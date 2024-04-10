#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],b[100001],c[1000001];
long long ans,x,y,l;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
     //   ans+=a[x];
       // ans+=b[y];
       // a[x]++; b[y]++;
        l=x+y;
        ans+=c[l+10000];
       // cout<<c[l+10000]<<" ";
        ++c[l+10000];
        l=x-y+1000;
        ans+=c[l];
       // cout<<c[l]<<endl;
        ++c[l];
    }
    cout<<ans;
}