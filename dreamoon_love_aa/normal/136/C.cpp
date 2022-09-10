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
int a[1000000];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    if(a[n-1]==1)a[n-1]=2;
    else a[n-1]=1;
    sort(a,a+n);
    for(i=0;i<n;i++){
        printf("%d%c",a[i],(i==n-1)?'\n':' ');
    }
    return 0;
}