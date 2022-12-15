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
long long mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    long long n,m,l,r;
    cin>>n>>m>>l>>r;
    if(n*m%2){
        printf("%lld\n",qpow(r-l+1,n*m));
    }
    else if((r-l+1)%2) printf("%lld\n",(qpow(r-l+1,n*m)+1)*qpow(2,mod-2)%mod);
    else printf("%lld\n",qpow(r-l+1,n*m)*qpow(2,mod-2)%mod);
    return 0;
}