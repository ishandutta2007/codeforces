#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    scanf("%I64d",&n);
    ll a[n];
    for(ll k=0;k<n;k++) scanf("%I64d",&a[k]);
    ll times=0;
    ll mm=1,pread=10000000,presh=1000000;
    while(mm<n)mm<<=1;
    for(ll k=0;k<n-1;k++){
        for(ll i=0;i<=k;i++){
            ll t=mm,sh=0,ad=0;
            if(i+pread>=n)
                while(ad+i < k+1){
                    if(ad+i+t<n) sh++,ad+=t;
                    t >>=1;
                }
            else ad=pread,sh=presh;
            a[i+ad] += a[i];
            times += a[i]*sh;
            a[i]=0;
            pread=ad;
            presh=sh;
        }
        printf("%I64d\n",times);
    }
    return 0;
}