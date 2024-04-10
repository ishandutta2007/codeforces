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
int a[111],b[111];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    if(n<=2)puts("-1");
    else{
        for(i=n;i>0;i--){
            if(i!=n)printf(" ");
            printf("%d",i);
        }
        puts("");
    }
    return 0;
}