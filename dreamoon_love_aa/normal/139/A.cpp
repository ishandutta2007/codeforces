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
int d[8];
int main(){
    int i,j,k=1,n;
    cin>>n;
    for(i=1;i<=7;i++)cin>>d[i];
    while(n>0){
        n-=d[k];
        if(n<=0)break;
        k++;
        if(k>7)k=1;
    }
    printf("%d\n",k);
    return 0;
}