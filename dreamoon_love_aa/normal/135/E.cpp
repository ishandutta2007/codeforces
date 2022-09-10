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
#define MOD 1000000007
#define SIZE 1000001
using namespace std;
long long mypow(long long x,int y){
    long long an=1;
    while(y){
        if(y&1){an*=x;an%=MOD;}
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return an;
}
int d[SIZE];
int f(int k,int w){
    memset(d,0,sizeof(d));
    d[k]=w;
    long long an=mypow(k,w);
    long long tmp=an;
    int now=k;
    for(int i=k-1;i;i--){
        d[i]+=2;
        tmp*=mypow(i,2);
        tmp%=MOD;
        while(d[now]==1)now--;
        d[now]--;
        tmp*=mypow(now,MOD-2);
        tmp%=MOD;
        an+=tmp;
        if(an>=MOD)an-=MOD;
    }
    //printf("an:%I64d\n",an);
    return an;
}
int main(){
    int i,j,k,w;
    scanf("%d%d",&k,&w);
    int an=f(k,w+1)-f(k,w);
    if(an<0)an+=MOD;
    an+=mypow(k,w);
    if(an>=MOD)an-=MOD;
    printf("%d\n",an);
    return 0;
}