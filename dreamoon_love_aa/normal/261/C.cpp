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
long long C[55][55];
long long g(int t,int x,long long n){
    if(t<0||n==0)return 0;
    if(x==0){
        if(t==0)return 1;
        return 0;
    }
    if(n<=(1ll<<(x-1)))return g(t,x-1,n);
    else{
        return C[x-1][t]+g(t-1,x-1,n-(1ll<<(x-1)));
    }
}
long long f(int t,long long n){
    if(t<0)return 0;
    long long res=0;
    long long two;
    int i;
    for(i=1,two=2;two<=n;i++,two<<=1){
        res+=C[i][t];
        n-=two;
    }
    return res+g(t,i,n);
}
int bit(long long x){
    int res=0;
    x>>=1;
    while(x){
        x>>=1;
        res++;
    }
    return res;
}
int main(){
    int i,j,k;
    long long n,t;
    cin>>n>>t;
    if(t&(t-1)){
        puts("0");
        return 0;
    }
    for(i=0;i<55;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    cout<<f(bit(t),n);
    return 0;
}