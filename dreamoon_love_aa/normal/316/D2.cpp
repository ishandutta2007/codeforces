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
#define SIZE 1000010
long long dp[SIZE][3],inv[SIZE],fac[SIZE];
long long mypow(long long x,long long y){
    long long res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
int main(){
    int i,j,k,n,d[3]={};
    fac[0]=1;
    for(i=1;i<SIZE;i++)fac[i]=fac[i-1]*i%MOD;
    inv[SIZE-1]=mypow(fac[SIZE-1],MOD-2);
    for(i=SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0)d[0]++;
        else if(x==1)d[1]++;
        else d[2]++;
    }
    n=d[1]+d[2];
    long long res=0,now=1;
    res=now;
    int cnt=1;
    for(i=d[1];i>1;i-=2){
        now=now*i%MOD;
        now=now*(i-1)%MOD;
        now=now*inv[2]%MOD;
        
        res+=now*inv[cnt]%MOD;
        if(res>=MOD)res-=MOD;
        cnt++;
    }
    for(i=d[1]+1;i<=d[1]+d[2];i++){
        res=res*i%MOD;
    }
    cout<<res<<endl;
    return 0;
}