#include <bits/stdc++.h>
using namespace std;
int n,k;
long long x,y,ans=-100000000000;

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        if (y<=k) ans=max(ans,x);
        else ans=max(ans,x-(y-k));
    }
    cout<<ans;
}