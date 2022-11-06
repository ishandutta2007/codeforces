#include<bits/stdc++.h>
using namespace std;
long long Sqrt(long long x){
    long long l=1,r=2000000001LL;
    long long mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(mid*mid<=x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
long long calc(long long x){
    long long s1=Sqrt(x);
    long long s2=Sqrt(x+1LL)-1;
    long long tmp = (Sqrt(4*x+1)-1)/2;
    return s1+s2+tmp;
}
void work(){
    long long l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",calc(r)-calc(l-1));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}