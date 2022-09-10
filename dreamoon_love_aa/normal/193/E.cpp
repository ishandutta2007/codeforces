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
long long n,A[50][2][2],B[50][2];
int a[1000];
long long mul(long long x,long long y,long long mod){
    long long res=0;
    while(y){
        if(y&1){
            res+=x;
            if(res>=mod)res-=mod;
        }
        x+=x;
        if(x>=mod)x-=mod;
        y>>=1;
    }
    return res;
}
void go(long long x,vector<long long>&e,long long mod){
    int i,j,k;
    long long xx=x;
    if(x==0){
        if(n%mod==0)e.pb(xx);
        return;
    }
    A[0][0][0]=0;
    A[0][0][1]=A[0][1][0]=A[0][1][1]=1;
    B[0][0]=0;
    B[0][1]=1;
    x--;
    int now=0;
    while(x){
        if(x&1){
            for(i=0;i<2;i++)B[now+1][i]=0;
            for(i=0;i<2;i++)
                for(j=0;j<2;j++){
                    B[now+1][i]+=mul(A[now][i][j],B[now][j],mod);
                    if(B[now+1][i]>=mod)B[now+1][i]-=mod;
                }
        }
        else for(i=0;i<2;i++)B[now+1][i]=B[now][i];
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)A[now+1][i][j]=0;
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++){
                    A[now+1][i][k]+=mul(A[now][i][j],A[now][j][k],mod);
                    if(A[now+1][i][k]>=mod)A[now+1][i][k]-=mod;
                }
        x>>=1;
        now++;
    }
    if(B[now][1]==n%mod)e.pb(xx);
}
int main(){
    int i,j,k;
    cin>>n;
    a[1]=1;
    vector<long long>d;
    if(n%1000==0)d.pb(0);
    if(n%1000==1)d.pb(1);
    for(i=2;i<1500;i++){
        a[i]=(a[i-1]+a[i-2])%1000;
        if(a[i]==n%1000)d.pb(i);
    }
    long long ten=1000;
    while(ten<10000000000000ll&&d.size()>0){
        vector<long long>e;
        for(j=0;j<10;j++)
            for(i=0;i<d.size();i++){
                go(d[i]+ten*j/2*3,e,ten*10);
            }
        d=e;
        ten*=10;
    }
    if(d.size()==0)puts("-1");
    else cout<<d[0]<<endl;
    return 0;
}