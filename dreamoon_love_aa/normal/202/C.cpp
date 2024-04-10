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
#define SIZE 101
int mi[SIZE];
int main(){
    int i,j,k,n,x;
    for(i=1;i<=100;i++)mi[i]=10000;
    for(i=1;i<=100;i++){
        if(i&1){
            for(j=1;j<=100&&j+j-1<=i*i;j++)mi[j]=min(mi[j],i);
        }
        else{
            for(j=2;j<=100&&j+j<=i*i-2*i;j+=2)mi[j]=min(mi[j],i);
        }
    }
    mi[3]=5;
    while(scanf("%d",&x)==1){
        printf("%d\n",mi[x]);
    }
    return 0;
}