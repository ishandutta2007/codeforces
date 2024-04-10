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
int a[2][100010],cnt[2],d[2][200010],dn[2],n[2];
int get(int x){
    if(x<=n[0])return a[0][x];
    return a[1][x-n[0]];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    for(k=0;k<2;k++){
        scanf("%d",&n[k]);
        for(i=1;i<=n[k];i++)scanf("%d",&a[k][i]);
    }
    for(k=0;k<2;k++){
        int k1=n[0],k2=n[1],now=k;
        while(k1>0||k2>0){
            cnt[k]++;
            while(k1>0&&a[0][k1]==now){
                d[k][dn[k]++]=k1--;
            }
            while(k2>0&&a[1][k2]==now){
                d[k][dn[k]++]=(k2--)+n[0];
            }
            now^=1;
        }
    }
    int an=0;
    for(i=dn[an]-1;i>=0;i--){
        if(i!=dn[an]-1)printf(" ");
        printf("%d",d[an][i]);
    }
    puts("");
    printf("%d\n",cnt[an]-1);
    int flag=0;
    for(i=dn[an]-1;i>0;i--){
        if(get(d[an][i])!=get(d[an][i-1])){
            if(flag)printf(" ");
            else flag=1;
            printf("%d",dn[an]-i);
        }
    }
    if(get(d[an][0])==1){
        if(flag)printf(" ");
        printf("%d",dn[an]);
    }
    puts("");
    return 0;
}