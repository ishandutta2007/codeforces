#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int cnt_bit(long long x){
    int res=0;
    while(x){
        res++;
        x>>=1;
    }
    return res;
}
long long g(int flag,int sub,int len,long long x){
    if(!flag){
        return 1ll<<(sub-1);
    }
    else{
        long long tmp=x>>(len-sub);
        x&=(1ll<<(len-sub))-1;
        for(int i=len/sub-1;i>0;i--){
            long long tmp2=x>>((i-1)*sub);
            if(tmp2<tmp){tmp--;break;}
            else if(tmp2>tmp)break;
            x&=(1ll<<((i-1)*sub))-1;
        }
        return tmp-(1ll<<(sub-1))+1;
    }
}
long long f(long long x){
    if(x==0)return 0;
    long long res=0;
    int bb=cnt_bit(x);
    int i,j,k;
    for(i=2;i<=bb;i++){
        long long dp[88]={};
        for(j=1;j*2<=i;j++){
            if(i%j!=0)continue;
            dp[j]=g(i==bb?1:0,j,i,x);
            for(k=1;k<j;k++){
                if(j%k==0)dp[j]-=dp[k];
            }
            res+=dp[j];
        }
    }
    return res;
}
int main(){
    int i,j,k,n;
    long long l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1)<<endl;
    return 0;
}