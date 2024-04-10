#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll calc_even(ll r){
    r %= mod;
    return r * (r + 1)% mod;
}
ll calc_odd(ll r){
    if (r == 0)return 0;
    return (calc_even(r) - r% mod + mod ) % mod;
}
ll calc(ll r){
    if (r == 0)return 0;
    unsigned long long len = 1;
    for (ll i = 0,j=0,first = 1;;first ^=1,len <<= 1){
        if (r >= len){
            if (first){
                i += len;
            }else{
                j += len;
            }
            r -= len;
        }else{
            if (first){
                i += r;
            }else{
                j += r;
            }
            return (calc_odd(i) + calc_even(j))% mod;
        }
    }
}
int main(){
    ll l,r;
    cin>>l>>r;
    cout<<(calc(r) - calc(l-1) + mod  + mod) % mod << endl;
    return 0;
}