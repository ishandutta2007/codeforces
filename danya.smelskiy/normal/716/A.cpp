#include <bits/stdc++.h>
using namespace std;
int n,c,x,ans,last;
int main(){
    cin>>n>>c;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x-last>c) ans=1;
        else ++ans;
        last=x;
    }
    cout<<ans;
}