#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n){
    if(!n)return 0;
    ll x=sqrt(n);
    while((x+1)*(x+1)<=n)x++;
    while(x*x>n)x--;
    return 3*(x-1)+1+(x*(x+1)<=n)+(x*(x+2)<=n);
}

void mian(){
    ll l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1)<<'\n';
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