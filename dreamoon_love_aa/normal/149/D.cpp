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
char s[777];
int f(int &idx,long long d[351][4]){
    int i,j,first=1,now=0;
    d[0][0]=1;
    while(s[idx]&&s[idx]!=')'){
        long long nd[351][4]={};
        idx++;
        int ha=f(idx,nd);
        long long nnd[351][4]={};
        for(i=0;i<=ha;i++){
            nnd[i+1][1]+=nd[i][0];
            nnd[i+1][2]+=nd[i][0];
            nnd[i][1]+=nd[i][1];
            nnd[i+1][2]+=nd[i][1];
            nnd[i][2]+=nd[i][2];
            nnd[i+1][1]+=nd[i][2];
            nnd[i][1]+=nd[i][3];
            nnd[i][2]+=nd[i][3];
        }
        ha++;
        for(i=0;i<=ha;i++)
            for(j=0;j<3;j++)nnd[i][j]%=MOD;
        if(first){
            memcpy(d,nnd,1404*sizeof(long long));
            first=0;
        }
        else{
            long long rd[351][4]={};
            for(i=0;i<=now;i++){
                for(j=0;j<=ha;j++){
                    for(int k1=0;k1<4;k1++)
                        for(int k2=0;k2<4;k2++){
                            int tmp1=i+j;
                            if((k1&2)&&(k2&1))tmp1--;
                            int tmp2=(k1&1)|(k2&2);
                            if(tmp1<0)continue;
                            rd[tmp1][tmp2]=(rd[tmp1][tmp2]+d[i][k1]*nnd[j][k2])%MOD;
                        }
                }
            }
            memcpy(d,rd,1404*sizeof(long long));
        }
        now+=ha;
    }
    idx++;
    return now;
}
int main(){
    int i,j,k,n;
    scanf("%s",s);
    long long dp[351][4]={};
    int idx=0;
    f(idx,dp);
    long long an=0;
    for(i=350;i>=0;i--){
        an<<=1;
        for(j=0;j<4;j++){
            an+=dp[i][j];
            an%=MOD;
        }
    }
    cout<<an<<endl;
    return 0;
}