#include <bits/stdc++.h>
using namespace std;
int n,ans,x,y,z;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y>>z;
        if (x+y+z>=2) ++ans;
    }
    cout<<ans;
}