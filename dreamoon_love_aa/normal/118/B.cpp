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
#define SIZE 20
int a[SIZE][SIZE];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    memset(a,-1,sizeof(a));
    for(i=0;i<=2*n;i++)
        for(j=0;j<=2*n;j++)
            if(abs(i-n)+abs(j-n)<=n)
                a[i][j]=n-abs(i-n)-abs(j-n);
    for(i=0;i<=n*2;i++){
        if(i<=n)k=n+i;
        else k=n*3-i;
        for(j=0;j<=k;j++){
            if(j)putchar(' ');
            if(a[i][j]<0)putchar(' ');
            else printf("%d",a[i][j]);
        }
        puts("");
    }
    return 0;
}