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
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yo[1000];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int mm,dd,p,t;
        scanf("%d%d%d%d",&mm,&dd,&p,&t);
        int now=111;
        for(j=1;j<mm;j++)now+=d[j];
        now+=dd;
        for(j=1;j<=t;j++)yo[now-j]+=p;
    }
    int an=0;
    for(i=0;i<1000;i++)an=max(an,yo[i]);
    printf("%d\n",an);
    return 0;
}