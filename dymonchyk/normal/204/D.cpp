#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#pragma comment("/:STACK:64000000",linker)

using namespace std;

char str[1000002];
int mod=1000000007;
int dp1[1000002];
int dp2[1000002];
int howX[1000002];
int sum[1000002];
int howW[1000002];
int howB[1000002];
int add[2000002];

int mPow(int a,int x) {
    int ret=1;
    while(x) {
        if (x&1) ret=(1LL*ret*a)%mod;
        a=(1LL*a*a)%mod; x>>=1;
    }
    return ret;
}

int getX(int l,int r) {
    if (l>r) return 0;
    return howX[r]-(l==0 ? 0 : howX[l-1]);
}

int getB(int l,int r) {
    if (l>r) return 0;
    return howB[r]-(l==0 ? 0 : howB[l-1]);
}

int getW(int l,int r) {
    if (l>r) return 0;
    return howW[r]-(l==0 ? 0 : howW[l-1]);
}

int pow2[1000002];

int getS(int l,int r) {
    if (l>r) return 0;
    return (sum[r]-(l==0 ? 0 : sum[l-1])+mod)%mod;
}

int getS2(int l,int r) {
    if (l>r) return 0;
    return (sum[l]-sum[r+1]+mod)%mod;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d\n",&n,&k); gets(str);
    howX[0]=str[0]=='X';
    howW[0]=str[0]=='W';
    howB[0]=str[0]=='B';
    for(int i=1;i<n;++i) {
        howX[i]=howX[i-1]+(str[i]=='X');
        howW[i]=howW[i-1]+(str[i]=='W');
        howB[i]=howB[i-1]+(str[i]=='B');
    }
    pow2[0]=1;
    for(int i=1;i<=1000000;++i)
        pow2[i]=(2LL*pow2[i-1])%mod;
    add[0]=sum[0]=dp1[0]=(k==1&&str[0]!='W');
    for(int i=1;i<n;++i) {
        if (i>=k-1&&getW(i-k+1,i)==0) {
            dp1[i]=pow2[getX(0,i-k)]-getS(i-k+1,i-1);
            if (dp1[i]<0) dp1[i]+=mod;
            dp1[i]-=add[i-k];
            if (dp1[i]<0) dp1[i]+=mod;
        }
        if (str[i]=='X') add[i]=(2LL*add[i-1]+dp1[i])%mod;
        else add[i]=(add[i-1]+dp1[i])%mod;
        sum[i]=sum[i-1]+dp1[i];
        if (sum[i]>=mod) sum[i]-=mod;
    }
    memset(sum,0,sizeof(sum));
    memset(add,0,sizeof(add));
    add[n-1]=sum[n-1]=dp2[n-1]=(k==1&&str[n-1]!='B');
    for(int i=n-2;i>=0;--i) {
        if (i<=n-k&&getB(i,i+k-1)==0) {
            dp2[i]=pow2[getX(i+k,n-1)]-getS2(i+1,i+k-1);
            if (dp2[i]<0) dp2[i]+=mod;
            dp2[i]-=add[i+k];
            if (dp2[i]<0) dp2[i]+=mod;
        }
        if (str[i]=='X') add[i]=(2LL*add[i+1]+dp2[i])%mod;
        else add[i]=(add[i+1]+dp2[i])%mod;
        sum[i]=sum[i+1]+dp2[i];
        if (sum[i]>=mod) sum[i]-=mod;
    }
//  for(int i=0;i<n;++i)
//      cout << dp1[i] << endl;
//  cout << endl;
//  for(int i=0;i<n;++i)
//      cout << dp2[i] << endl;
//  cout << endl;
//  for(int i=1;i<n;i++)
//      dp1[i]=(dp1[i]+dp1[i-1])%mod;
    for(int i=n-1;i>=0;--i) {
        if (str[i]=='X') dp2[i]=(2LL*dp2[i+1]+dp2[i])%mod;
        else dp2[i]+=dp2[i+1];
        if (dp2[i]>=mod) dp2[i]-=mod;
    }
    int ans=0;
    for(int i=0;i<n;++i)
        ans=(ans+1LL*dp1[i]*dp2[i+1])%mod;
    cout << ans << endl;
    return 0;
}