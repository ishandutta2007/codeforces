#include <bits/stdc++.h>
using namespace std;
int x,ans;
int main(){
    for (int i=1;i<=5;++i){
        cin>>x;
        ans+=x;
    }
    if (ans==0) cout<<"-1"; else
    if (ans%5==0 ) cout<<ans/5;
    else cout<<"-1";
}