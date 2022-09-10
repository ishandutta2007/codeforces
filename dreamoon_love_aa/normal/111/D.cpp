#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const long long MOD=1000000007ll;
struct gcd_t{long long x,y,z;};
gcd_t gcd(long long a,long long b){
    if(!b)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
long long inv(long long x){
    gcd_t tmp=gcd(MOD,x);
    if(tmp.y<0)tmp.y+=MOD;
    return tmp.y;
}
int k;
long long C[2001][2001],dp[1001],haha[2001];
long long pow(long long x,int y){
    long long an=1;
    if(x==0){
        if(y==0)return 1;
        return 0;
    }
    while(y){
        if(y&1){
            an*=x;
            an%=MOD;
        }
        x=(x*x)%MOD;
        y>>=1;
    }
    return an;
}
long long CC(int x,int y){
    if(x<=2000){
        if(y>x)return 0;
        return C[x][y];
    }
    return haha[y];
}
int main(){
    int n,m,i,j,all;
    long long an=0;
    for(i=0;i<=2000;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    scanf("%d%d%d",&n,&m,&k);
    haha[0]=1;
    for(i=1;i<=2000&&i<=k;i++){
        haha[i]=(haha[i-1]*(k-i+1))%MOD;
        haha[i]=(haha[i]*inv(i))%MOD;
    
    }
    if(m==1){
        an=pow(k,n);
        if(an<0)an+=MOD;
        cout<<an<<endl;
        return 0;
    }
    for(i=1;i<=n;i++){
        dp[i]=pow(i,n);
        for(j=1;j<i;j++){
            dp[i]-=dp[j]*C[i][j];
            dp[i]%=MOD;
        }
        if(dp[i]<0)dp[i]+=MOD;
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=i;j++){
            all=i+i-j;
            if(all>k)continue;
            an+=((((pow(j,n*(m-2))*CC(k,all))%MOD)*((CC(all,j)*CC(all-j,(all-j)>>1))%MOD))%MOD)*((dp[i]*dp[i])%MOD);
            an%=MOD;
        }
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}