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
int d[20];
int main(){
    int i,j,k,n,a,b;
    cin>>n>>b>>a;
    if(!a){
        if(!b){
            for(i=1;i<=n;i++){
                if(i!=1)putchar(' ');
                printf("1");
            }
            puts("");
        }
        else if(b==n-1)puts("-1");
        else{
            printf("5 1");
            for(i=1;i<=b;i++)printf(" %d",i+5);
            for(i=b+3;i<=n;i++)printf(" 1");
            puts("");
        }
    }
    else{
        d[1]=1;
        printf("%d",1);
        for(i=1;i<=a;i++){
            d[i+1]=1<<i;
            printf(" %d",1<<i);
        }
        for(i=a+2;i<=a+b+1;i++){
            d[i]=d[i-1]+1;
            printf(" %d",d[i]);
        }
        for(i=a+b+2;i<=n;i++){
            printf(" 1");
        }
        puts("");
    }
    return 0;
}