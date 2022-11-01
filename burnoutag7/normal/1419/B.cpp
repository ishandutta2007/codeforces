#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    ll x,ans=0,c=1;
    cin>>x;
    while(true){
        c<<=1;
        if((c-1)*c>>1<=x){
            ans++;
            x-=(c-1)*c>>1;
        }else break;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}