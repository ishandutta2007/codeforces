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
int main(){
    int i,j,k,n;
    cin>>n>>k;
    if(k*3>n){
        puts("-1");
        return 0;
    }
    for(i=1;i<=k;i++){
        if(i!=1)printf(" ");
        printf("%d",i);
    }
    n-=k;
    for(i=1;i<=k;i++){
        if(i<=n%k)
            for(j=0;j<n/k+1;j++)printf(" %d",i);
        else
            for(j=0;j<n/k;j++)printf(" %d",i);
    }
    puts("");
    return 0;
}