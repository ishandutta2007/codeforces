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
int a[12];
int main(){
    int i,j,k=0,n;
    cin>>n;
    if(n==0){
        puts("0");
        return 0;
    }
    for(i=0;i<12;i++)cin>>a[i];
    sort(a,a+12);
    for(j=1;j<=12;j++){
        n-=a[12-j];
        if(n<=0)break;
    }
    if(j>12)puts("-1");
    else printf("%d\n",j);
    return 0;
}