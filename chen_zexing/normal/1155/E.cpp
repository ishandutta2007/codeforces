#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int n=11;
long long a[12][12],ans[12];
long long mod=1e6+3;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long inv(long long x){
    return qpow(x,mod-2);
}
long long query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    long long t;
    scanf("%lld",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        for(int i=1;i<=11;i++){
            for(int j=1;j<=11;j++) a[i][j]=qpow(i,j-1);
            a[i][n+1]=query(i);
        }
        for(int i=1;i<=n;i++){
            int mx=i;
            for(int j=i+1;j<=n;j++)
                if(a[j][i]>a[mx][i])
                    mx=j;
            for(int j=1;j<=n+1;j++) swap(a[i][j],a[mx][j]);
            for(int j=1;j<=n;j++)
                if(j!=i){
                    long long d=a[j][i]*inv(a[i][i])%mod;
                    for(int k=i+1;k<=n+1;k++)
                        a[j][k]-=a[i][k]*d%mod,a[j][k]=(a[j][k]%mod+mod)%mod;
                }
        }
        for(int i=1;i<=n;i++) ans[i]=a[i][n+1]*inv(a[i][i])%mod;
        for(int i=0;i<mod;i++){
            long long temp=0;
            for(int j=1;j<=11;j++) temp+=qpow(i,j-1)*ans[j]%mod,temp%=mod;
            if(temp==0){
                printf("! %d\n",i);
                exit(0);
            }
        }
        puts("! -1");
    }
    return 0;
}
//
/// 
//01
//