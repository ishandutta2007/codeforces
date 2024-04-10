#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int sod(ll x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

void mian(){
    ll n,m;
    int s;
    cin>>n>>s;
    m=n;
    for(ll c=1;sod(n)>s;c*=10)n+=(10-n/c%10)%10*c;
    cout<<n-m<<'\n';
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