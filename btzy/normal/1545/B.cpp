#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=100000;
constexpr int MOD=998244353;
bool arr[MAXN];
int fact[MAXN+1],invfact[MAXN+1];
int powmod(int base, int exp){
    if(exp==1)return base;
    int res=powmod(base,exp/2);
    res*=res;
    res%=MOD;
    if(exp&1){
        res*=base;
        res%=MOD;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    fact[0]=1;
    invfact[0]=1;
    for(int i=1;i<=MAXN;++i){
        fact[i]=(fact[i-1]*i)%MOD;
        invfact[i]=powmod(fact[i],MOD-2);
    }
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            char ch;
            cin>>ch;
            arr[i]=ch!='0';
        }
        int numzero=0;
        int numone=0;
        int lastone=0;
        for(int i=0;i<n;++i){
            if(!arr[i]){
                numone+=lastone/2;
                lastone=0;
                ++numzero;
            }
            else{
                ++lastone;
            }
        }
        numone+=lastone/2;
        int ans=fact[numzero+numone];
        ans*=invfact[numzero];
        ans%=MOD;
        ans*=invfact[numone];
        ans%=MOD;
        cout<<ans<<'\n';
    }
}