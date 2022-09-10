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
#define SIZE 100001
int a[SIZE],b[SIZE],p[SIZE];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i++)p[a[i]]=b[i];
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",p[i]);
    }
    puts("");
    return 0;
}