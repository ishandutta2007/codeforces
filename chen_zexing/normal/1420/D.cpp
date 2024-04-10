#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
struct operation{
    long long time,type;
}a[600005];
bool cmp(operation a,operation b){
    return a.time<b.time;
}
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
long long multi[300005];
long long c(long long n,long long m){
    if(n<m) return 0;
    long long ans=multi[n];
    ans=ans*qpow(multi[m],mod-2)%mod;
    ans=ans*qpow(multi[n-m],mod-2)%mod;
    return ans;
}
int main() {
    multi[0]=multi[1]=1;
    for(int i=2;i<=300000;i++) multi[i]=multi[i-1]*i%mod;
    long long n,k,t;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&t);
        operation x;
        x.time=t,x.type=1;
        a[i*2-1]=x;
        scanf("%lld",&t);
        x.time=t+1,x.type=2;
        a[i*2]=x;
    }
    sort(a+1,a+2*n+1,cmp);
    long long ans=0,cnt=0,p;
    for(int i=1;i<=n*2;i++){
        int j=i;
        p=0;
        int f1=0,f2=0;
        while(a[j].time==a[i].time){
            if(a[j].type==1) p++,f1++;
            else p--,f2++;
            j++;
        }
        i=j-1;
        if(f1>0&&cnt+p>=k) ans=(ans+c(cnt+p,k)%mod-c(cnt-f2,k)%mod)%mod;
        //cout<<a[i].time<<" "<<ans<<endl;
        cnt+=p;
    }
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}