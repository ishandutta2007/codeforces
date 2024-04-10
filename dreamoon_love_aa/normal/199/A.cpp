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
#define MAX 1000000000
using namespace std;
long long a[1000];
int main(){
    int i,j,k,n;
    a[0]=0;
    a[1]=1;
    for(i=2;i<=100;i++)a[i]=a[i-1]+a[i-2];
    cin>>n;
    for(i=0;i<=100;i++)
        for(j=0;j<=100;j++)
            for(k=0;k<=100;k++){
                if(a[i]+a[j]+a[k]==n){
                    printf("%I64d %I64d %I64d\n",a[i],a[j],a[k]);
                    return 0;
                }
            }
    puts("I'm too stupid to solve this problem");
    return 0;
}