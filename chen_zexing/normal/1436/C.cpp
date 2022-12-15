#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
long long multi[1005];
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
long long c(long long a,long long b){
    if(a<b) return 0;
    return multi[a]*qpow(multi[b],mod-2)%mod*qpow(multi[a-b],mod-2)%mod;
}
int main() {
    int n,x,pos;
    cin>>n>>x>>pos;
    multi[0]=1;
    for(int i=1;i<=n;i++) multi[i]=multi[i-1]*i%mod;
    int l=0,r=n;
    int cnt1=0,cnt2=0;
    while(l<r){
        int mid=(l+r)/2;
        if(mid<pos){
            cnt1++;
            l=mid+1;
        }
        else if(mid>pos){
            cnt2++;
            r=mid;
        }
        else l=mid+1;
    }
    //cout<<cnt1<<" "<<cnt2<<endl;
    long long ans=1;
    ans*=c(x-1,cnt1);
    //cout<<c(x-1,cnt1)<<endl;
    ans%=mod;
    ans=ans*c(n-x,cnt2)%mod;
    ans=ans*multi[n-cnt1-cnt2-1]%mod;
    ans=ans*multi[cnt1]%mod;
    ans=ans*multi[cnt2]%mod;
    cout<<ans<<endl;
    return 0;
}