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
#define SIZE 111
int mi[SIZE],ma[SIZE],love[SIZE],all_mi,all_ma;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,m;
    scanf("%d%d",&m,&k);
    for(i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        love[x]=1;
    }
    scanf("%d",&n);
    all_mi=10000;
    all_ma=0;
    for(i=1;i<=n;i++){
        char nouse[111];
        int dn,unknow=0,yi=0,not_yi=0;
        scanf("%s",nouse);
        scanf("%d",&dn);
        for(j=1;j<=dn;j++){
            int x;
            scanf("%d",&x);
            if(!x)unknow++;
            else if(love[x])yi++;
            else not_yi++;
        }
        mi[i]=yi+max(0,unknow-(m-k-not_yi));
        ma[i]=yi+min(k-yi,unknow);
        all_mi=min(all_mi,ma[i]);
        all_ma=max(all_ma,mi[i]);
    }
    for(i=1;i<=n;i++){
        //printf("[%d,%d]\n",mi[i],ma[i]);
        for(j=1;j<=n;j++){
            if(i==j)continue;
            if(mi[i]<ma[j])break;
        }
        if(j>n){
            puts("0");
            continue;
        }
        for(j=1;j<=n;j++){
            if(i==j)continue;
            if(mi[j]>ma[i])break;
        }
        if(j<=n){
            puts("1");
            continue;
        }
        puts("2");
    }
    return 0;
}