//
// Created by calabash_boy on 18-6-19.
//
/*header*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD = 1e9+7;
const int maxn =10000;
typedef vector<int> vi;
#define rep(x,y,z) for (int x=y;x<z;x++)
LL power(LL x,LL y){
    LL res =1;
    while (y){
        if(y&1){
            res = res*x%MOD;
        }
        y>>=1;
        x = x*x%MOD;
    }
    return res;
}
int main(){
    LL x,k;
    cin>>x>>k;
    if(x==0){
        cout<<0<<endl;
        return 0;
    }
    x%=MOD;
    LL ans = 1LL*power(2,k+1)*x%MOD-(power(2,k)-1+MOD)%MOD;
    ans = (ans+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}