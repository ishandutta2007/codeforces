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
int dd(long long x){
    long long res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    int i,j,k;
    long long n;
    cin>>n;
    long long ll=1,rr=1000000000;
    while(ll<rr){
        long long mm=(ll+rr)/2;
        if(mm*mm+dd(mm)*mm<n)ll=mm+1;
        else rr=mm;
    }
    for(i=max(1ll,ll-100);i<=ll+100;i++){
        if((long long)i*i+(long long)dd(i)*i==n)break;
    }
    if(i<=ll+100)printf("%d\n",i);
    else puts("-1");
    return 0;
}