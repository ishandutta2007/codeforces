#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int a[1001];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    while(!a[k]){
        k++;
        if(k>n)k=1;
    }
    printf("%d\n",k);
    return 0;
}