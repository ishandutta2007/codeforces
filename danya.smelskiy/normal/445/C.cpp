#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y;
long double mass[100001];
long double ans,z;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>mass[i];
    }
    for (int i=1;i<=m;++i){
        cin>>x>>y>>z;
        long double k=(mass[x]+mass[y])/z;
        ans=max(ans,k);
    }
    cout<<fixed<<" "<<setprecision(10)<<ans;
}