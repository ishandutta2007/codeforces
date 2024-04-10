#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;

ll w,h,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>w>>h;
    ans=1;
    for(int i=1;i<=w;i++){
        ans*=2;
        ans%=mod;
    }
    for(int i=1;i<=h;i++){
        ans*=2;
        ans%=mod;
    }
    cout<<ans<<endl;

    return 0;
}