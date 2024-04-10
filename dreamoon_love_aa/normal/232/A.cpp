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
#define SIZE 100
using namespace std;
int a[SIZE][SIZE];
int main(){
    int i,j,k,n,base;
    cin>>k;
    for(i=0;;i++)
        if((i+1)*i*(i-1)/6>k)break;
    base=i;
    for(i=0;i<base;i++)
        for(j=0;j<base;j++){
            if(i!=j)a[i][j]=1;
        }
    int now=base;
    k-=base*(base-1)*(base-2)/6;
    while(k>0){
        for(i=1;;i++){
            if(i*(i+1)/2>k)break;
        }
        for(j=0;j<i;j++)a[j][now]=a[now][j]=1;
        k-=i*(i-1)/2;
        now++;
    }
    printf("%d\n",now);
    for(i=0;i<now;i++,puts(""))
        for(j=0;j<now;j++)printf("%d",a[i][j]);
    return 0;
}