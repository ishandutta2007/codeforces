#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x<5 && x<=5-m) ++ans;
    }
    cout<<ans/3;
}