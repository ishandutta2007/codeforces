#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    ll k,x;
    cin>>k>>x;
    ll l=1,r=2*k-1,m,a=2*k-1,e;
    while(l<=r){
        m=l+r>>1;
        e=m<=k?(m+1)*m/2:(k+1)*k/2+(k-1+2*k-m)*(m-k)/2;
        if(e>=x){
            r=m-1;
            a=m;
        }else{
            l=m+1;
        }
    }
    cout<<a<<'\n';
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