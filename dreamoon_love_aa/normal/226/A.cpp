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
long long mod;
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=mod;
        }
        x*=x;
        x%=mod;
        y>>=1;
    }
    return res;
}
int main(){
    long long x;
    cin>>x>>mod;
    long long res=mypow(3,x);
    res--;
    if(res<0)res+=mod;
    cout<<res<<endl;
    return 0;
}