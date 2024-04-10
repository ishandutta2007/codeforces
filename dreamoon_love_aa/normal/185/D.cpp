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
long long mypow(long long x,long long y,long long mod){
    long long res=1;
    x%=mod;
    while(y){
        if(y&1){res*=x;res%=mod;}
        x*=x;
        x%=mod;
        y>>=1;
    }
    return res;
}
int main(){
    int i,j,n,T;
    long long k,l,r,p;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d%I64d",&k,&l,&r,&p);
        if(k==1){
            printf("%I64d\n",2%p);
            continue;
        }
        if(p==2){
            if(k%2)printf("0\n");
            else printf("1\n");
            continue;
        }
        if(k%p==0){
            if(k%2==0)printf("1\n");
            else printf("%I64d\n",mypow(mypow(2,r-l,p),p-2,p));
            continue;
        }
        long long up=mypow(k,mypow(2,r+1,p-1),p);
        long long down=mypow(k,mypow(2,l,p-1),p);
        if(up==1){
            if(down!=1)puts("0");
            else{
                if(k%2==0)printf("%I64d\n",mypow(2,r-l+1,p));
                else printf("2\n");
            }
        }
        else{
            if(k%2==0)printf("%I64d\n",(up+p-1)*mypow(down+p-1,p-2,p)%p);
            else printf("%I64d\n",((up+p-1)*mypow(down+p-1,p-2,p)%p)*mypow(mypow(2,r-l,p),p-2,p)%p);
        }
    }
    return 0;
}