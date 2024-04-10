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
#define MOD 1000000007
int a[2001];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){res*=x;res%=MOD;}
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
long long rev(long long x){
    return mypow(x,MOD-2);
}
long long an[2222];
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)cin>>a[i];
    if(k==0){
        for(i=1;i<=n;i++){
            if(i!=1)printf(" ");
            cout<<a[i];
        }
        puts("");
        return 0;
    }
    if(k==1){
        long long now=0;
        for(i=1;i<=n;i++){
            now+=a[i];
            now%=MOD;
            if(i!=1)printf(" ");
            cout<<now;
        }
        puts("");
        return 0;
    }
    for(i=1;i<=n;i++){
        long long tmp=1;
        for(j=i;j<=n;j++){
            an[j]+=tmp*a[i];
            an[j]%=MOD;
            tmp*=j-i+k;
            tmp%=MOD;
            tmp*=rev(j-i+1);
            tmp%=MOD;
        }
    }
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        cout<<an[i];
    }
    puts("");
    return 0;
}