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
long long dp[10][10],C[20],d[11][20][100];
int lucky(int x){return x==4||x==7;}
long long CC(long long x,long long y){
    if(y>x)return 0;
    long long res=1;
    for(int i=1;i<=y;i++){
        res=res*(x-y+i)%MOD;
        res=res*mypow(i,MOD-2)%MOD;
    }
    return res;
}
int main(){
    int i,j,k,n,m;
    dp[0][0]=1;
    dp[1][1]=2;
    dp[1][0]=8;
    for(i=1;i<9;i++){
        for(j=0;j<9;j++){
            dp[i+1][j]+=dp[i][j]*8;
            dp[i+1][j+1]+=dp[i][j]*2;
        }
    }
    char s[16];
    scanf("%d",&m);
    m++;
    sprintf(s,"%d",m);
    int len=strlen(s),ll=0;
    for(i=0;i<len;i++){
        s[i]-='0';
        for(j=0;j<s[i];j++){
            for(k=0;k<10;k++)C[k+ll+lucky(j)]+=dp[len-i-1][k];
        }
        ll+=lucky(s[i]);
    }
    C[0]--;
    //for(i=0;i<10;i++)printf("[%d]:%d\n",i,C[i]);
    d[0][0][0]=1;
    for(i=0;i<10;i++){
        for(j=6;j>=0;j--){
            long long tmp=CC(C[i],j);
            for(k=6;k>=0;k--){
                for(int kk=0;kk<10;kk++){
                    d[i+1][k+j][kk+j*i]+=d[i][k][kk]*tmp%MOD;
                    if(d[i+1][k+j][kk+j*i]>=MOD)d[i+1][k+j][kk+j*i]-=MOD;
                }
            }
        }
    }
    long long an=0;
    for(i=1;i<10;i++){
        for(j=0;j<i;j++)an+=C[i]*d[10][6][j]%MOD;
    }
    an%=MOD;
    for(i=1;i<=6;i++)an=an*i%MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}