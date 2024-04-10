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
#define MAX 1000000000
#define SIZE 100000 
using namespace std;
int a[SIZE],r[SIZE];
int main(){
    int i,j,k,n,mi=MAX,ma=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        mi=min(a[i],mi);
        ma=max(a[i],ma);
    }
    ma-=mi;
    for(i=0;i<n;i++){
        if(a[i]-mi>=n){
            puts("NO");
            return 0;
        }
        r[a[i]-mi]++;
    }
    int now=r[ma]*2;
    for(i=ma-1;i>0;i--){
        if(r[i]==0){
            puts("NO");
            return 0;
        }
        now=r[i]*2-now;
        if(now<=0){
            puts("NO");
            return 0;
        }
    }
    if(now==r[0]*2)puts("YES");
    else puts("NO");
    return 0;
}