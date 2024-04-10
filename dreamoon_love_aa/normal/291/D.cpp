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
int an[20][10001];
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        int tar=max(0,n-i-1);
        for(j=0;j<k;j++){
            if(!tar)an[j][i]=n;
            else{
                if(tar&(1<<j)){
                    an[j][i]=n-(1<<j);
                    tar-=1<<j;
                }
                else an[j][i]=n;
            }
        }
    }
    for(i=0;i<k;i++,puts(""))
        for(j=1;j<=n;j++){
            if(j!=1)printf(" ");
            printf("%d",an[i][j]);
        }
    return 0;
}