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
#define MOD 1000000007
using namespace std;
vector<int>lucky;
void dfs(int x){
    int y;
    if(x>=100000000)return;
    y=x*10+4;
    lucky.pb(y);
    dfs(y);
    y=x*10+7;
    lucky.pb(y);
    dfs(y);
}
int a[1024];
long long dp[1024],inv[100010],fac[100010];
long long mypow(long long x,long long y){
    long long an=1;
    while(y){
        if(y&1){
            an*=x;
            an%=MOD;
        }
        y>>=1;
        x*=x;
        x%=MOD;
    }
    return an;
}
int main(){
    int i,j,k,n,non=0,m;
    fac[0]=inv[0]=1;
    for(i=1;i<=100000;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    inv[100000]=mypow(fac[100000],MOD-2);
    for(i=99999;i>0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
    dfs(0);
    sort(lucky.begin(),lucky.end());
    scanf("%d%d",&n,&k);
    m=min((int)lucky.size(),k);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int tmp=lower_bound(lucky.begin(),lucky.end(),x)-lucky.begin();
        if(tmp>=lucky.size())non++;
        else if(lucky[tmp]==x)a[tmp]++;
        else non++;
    }
    dp[0]=1;
    for(i=0;i<lucky.size();i++){
        for(j=m;j>0;j--){
            dp[j]=(dp[j-1]*a[i]+dp[j])%MOD;
        }
    }
    long long an=0;
    for(i=0;i<=m;i++){
        if(k-i>non)continue;
        an+=dp[i]*fac[non]%MOD*inv[k-i]%MOD*inv[non-(k-i)]%MOD;
    }
    an%=MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}