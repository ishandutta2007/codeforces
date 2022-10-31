#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,ans;
int main(){
    cin>>n>>m>>a>>b;
    if (b<=m*a){
        ans=(n/m)*b+min(b,a*(n%m));
       // if (n%m>0) ans+=min(b,a*(n%m));
    } else ans=n*a;
    cout<<ans;
}