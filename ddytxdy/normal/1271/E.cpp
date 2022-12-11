#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k,anss;
LL check(LL x){
    if(x>n)return 0;int p=0;LL now=0;
    while((x<<p)+(1ll<<p)-1<=n)now+=1ll<<p,p++;
    if((x<<p)<=n)now+=(n&((1ll<<p)-1))+1;
    return now;
}
int main(){
    cin>>n>>k;
    LL l=0,r=n/2,ans=0;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(check(mid*2+1)>=k)ans=mid*2+1,l=mid+1;
        else r=mid-1;
    }
    anss=ans;
    l=1,r=n/2;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(check(mid*2)+check(mid*2+1)>=k)ans=mid*2,l=mid+1;
        else r=mid-1;
    }
    anss=max(anss,ans);
    cout<<anss;
    return 0;
}