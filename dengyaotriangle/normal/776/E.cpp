#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int mdn=1000000007;

long long n,k,s;

long long phi(long long x){
    long long t=x;
    long long ans=x;
    for(long long i=2;i*i<=x;i++){
        if(t%i==0){
            while(t%i==0)t/=i;
            ans=ans/(i)*(i-1);
        }
    }
    if(t!=1){
        ans=ans/t*(t-1);
    }
    return ans;
}
int main(){
    cin>>n>>k;
    s=(k+1)>>1;
    while(s--){
        long long nw=phi(n);
        if(nw==n)break;
        n=nw;
    }
    cout<<n%mdn;
    return 0;
}