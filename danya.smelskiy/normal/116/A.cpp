#include <bits/stdc++.h>
using namespace std;
int n,a,x,y,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        a-=x; a+=y;
        if (a>ans) ans=a;
    }
    cout<<ans;
}