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
#define SIZE 1000000
int a[SIZE];
int main(){
    int i,j,k,n,m;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(k>=m){
        puts("0");
        return 0;
    }
    for(i=n-1;i>=0;i--){
        k+=a[i]-1;
        if(k>=m)break;
    }
    if(i>=0)printf("%d\n",n-i);
    else puts("-1");
    return 0;
}