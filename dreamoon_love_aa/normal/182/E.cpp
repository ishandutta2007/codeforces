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
int a[111],b[111],dp[3001][222];
int cnt[111][111];
long long mypow(long long x,int y){
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
    int i,j,k,n,l;
    cin>>n>>l;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        cnt[min(a[i],b[i])][max(a[i],b[i])]++;
        dp[a[i]][i<<1]++;
        if(a[i]!=b[i])dp[b[i]][(i<<1)|1]++;
    }
    for(i=1;i<l;i++){
        for(j=0;j<(n<<1);j+=2){
            if(!dp[i][j])continue;
            for(k=0;k<n;k++){
                if(k==(j>>1))continue;
                if(i+a[k]<=l&&a[k]==b[j>>1]){
                    dp[i+a[k]][k<<1]+=dp[i][j];
                    if(dp[i+a[k]][k<<1]>=MOD)dp[i+a[k]][k<<1]-=MOD;
                }
                if(i+b[k]<=l&&a[k]!=b[k]&&b[k]==b[j>>1]){
                    dp[i+b[k]][(k<<1)|1]+=dp[i][j];
                    if(dp[i+b[k]][(k<<1)|1]>=MOD)dp[i+b[k]][(k<<1)|1]-=MOD;
                }
            }
        }
        for(j=1;j<(n<<1);j+=2){
            if(!dp[i][j])continue;
            for(k=0;k<n;k++){
                if(k==(j>>1))continue;
                if(i+a[k]<=l&&a[k]==a[j>>1]){
                    dp[i+a[k]][k<<1]+=dp[i][j];
                    if(dp[i+a[k]][k<<1]>=MOD)dp[i+a[k]][k<<1]-=MOD;
                }
                if(i+b[k]<=l&&a[k]!=b[k]&&b[k]==a[j>>1]){
                    dp[i+b[k]][(k<<1)|1]+=dp[i][j];
                    if(dp[i+b[k]][(k<<1)|1]>=MOD)dp[i+b[k]][(k<<1)|1]-=MOD;
                }
            }
        }
    }
    //for(i=1;i<=l;i++,puts(""))
    //    for(j=0;j<(n<<1);j++){
    //        cout<<dp[i][j]<<" ";
    //    }
    int an=0;
    for(i=0;i<(n<<1);i++){
        an+=dp[l][i];
        if(an>=MOD)an-=MOD;
    }
    /*
    for(i=1;i<=100;i++)
        for(j=i+1;j<=100;j++){
            if(cnt[i][j]>1&&l%(i+j)==0){
                //printf("(%d,%d)\n",i,j);
                an-=(cnt[i][j]*mypow(cnt[i][j]-1,l/(i+j)*2-1))%MOD;
                if(an<0)an+=MOD;
            }
        }
    */
    cout<<an<<endl;
    return 0;
}