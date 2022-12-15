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
#define hash hassh
using namespace std;
vector <long long> v;
long long mod=1000000007;
long long euler(long long n){
    long long res=n;
    for(long long i=2; i*i <=n; ++i){
        if( n % i ==  0){
            res = res/i*(i-1);
            while(n % i ==  0) n/=i;
        }
    }
    if(n>1) res = res / n * (n-1);
    return res;
}
long long qpow(long long a,long long b){
    a%=mod;
    b%=euler(mod);
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    long long x,n;
    long long ans=1;
    cin>>x>>n;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            v.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) v.push_back(x);
    for(int i=0;i<v.size();i++){
        long long t=v[i];
        while(t<=n){
            ans*=qpow(v[i],n/t);
            ans%=mod;
            if(n/v[i]<t) break;
            t*=v[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}