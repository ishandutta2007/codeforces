#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
long long F[90];
//int f(int x){return x/2+1;}
int main(){
    int i,j,k,T,m,d[100],dn,now;
    long long dp[100][2];
    long long n;
    F[0]=1;
    F[1]=2;
    for(i=2;;i++){
        F[i]=F[i-1]+F[i-2];
        if(F[i]>1000000000000000000ll)break;
    }
    m=i;
    scanf("%d",&T);
    while(T--){
        cin>>n;
        dn=now=0;
        for(j=m-1;j>=0;j--)
            if(n>=F[j]){
                n-=F[j];
                d[dn++]=j;
            }
        dn--;
        now=0;
        dp[0][1]=1;
        dp[0][0]=d[dn]>>1;
        while(dn>0){
            dn--;
            dp[now+1][0]=dp[now][0]*((d[dn]-d[dn+1])>>1)+dp[now][1]*((d[dn]-d[dn+1]-1)>>1);
            dp[now+1][1]=dp[now][0]+dp[now][1];
            now++;
        }
        cout<<dp[now][0]+dp[now][1]<<endl;
    }
    return 0;
}