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
int a[120],x[120],y[120],e[120][120],d;
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&d);
    for(i=2;i<n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)e[i][j]=MAX;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(i!=j){
                e[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*d-a[j];
            }
        }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
    printf("%d\n",e[1][n]);
    return 0;
}