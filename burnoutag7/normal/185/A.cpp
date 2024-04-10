#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

ll bp(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<(bp(2,n)+bp(4,n))%mod*bp(2,mod-2)%mod<<endl;

    return 0;
}