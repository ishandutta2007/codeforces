#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,ans;
long long a[1000001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=m;++i){
        cin>>l>>r;
        long long kol=0;
        for (int j=l;j<=r;++j)
            kol+=a[j];
        if (kol>=0){
            ans+=kol;
        }
       // cout<<ans<<endl;
    }
    cout<<ans;
}