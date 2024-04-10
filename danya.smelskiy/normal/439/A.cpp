#include <bits/stdc++.h>
using namespace std;
int n,d,ans,k,x;
int main(){
    cin>>n>>d;
    for (int i=1;i<=n;++i){
        cin>>x;
        k+=2;
        ans+=10+x;
    }
    ans-=10;
    k-=2;
    //cout<<ans<<" ";
    if (ans>d) cout<<"-1";
    else cout<<k+(d-ans)/5;
}