#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
long long mod=1000000007;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long cal(long long pos) {
    if (pos == 0) return 0;
    long long ans = 0;
    long long p[2] = {1, 1}, now = 1, f = 0, cnt = 0;
    while (cnt <= pos - now) {
        if (f == 0) {
            ans += ((p[f] * 2 - 1) * 2 + 2 * (now - 1)) % mod * (now % mod) % mod * qpow(2, mod - 2) % mod;
        }
        else ans += (p[f] * 2 * 2 + 2 * (now - 1)) % mod * (now % mod) % mod * qpow(2, mod - 2) % mod;
        ans %= mod;
        p[f] += now;
        cnt += now;
        f = 1 - f;
        now *= 2;
    }
    now = pos - cnt;
    //cout<<now<<endl;
    if (now == 0) return ans;
    if (f == 0) {
        ans += ((p[f] * 2 - 1) * 2 + 2 * (now - 1) % mod) % mod * (now % mod) % mod * qpow(2, mod - 2) % mod;
    }
    else ans += (p[f] * 2 * 2 + 2 * (now - 1)) % mod * (now % mod) % mod * qpow(2, mod - 2) % mod;
    ans %= mod;
    return ans;
}
int main() {
    long long l,r;
    cin>>l>>r;
    cout<<(cal(r)-cal(l-1)+mod)%mod<<endl;
    //cout<<cal(r)<<" "<<cal(l)<<endl;
    return 0;
}