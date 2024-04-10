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
int mm[66][66][66],a[66][66],n,r;
void pre(){
    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)mm[1][i][j]=min(mm[1][i][j],a[i][j]);
}
int main(){
    int i,j,k,m;
    scanf("%d%d%d",&n,&m,&r);
    for(k=1;k<=60;k++)
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)mm[k][i][j]=MAX;
    for(i=0;i<m;i++)
        pre();
    for(i=2;i<=60;i++){
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                for(int kk=1;kk<=n;kk++){
                    mm[i][j][kk]=min(mm[i][j][kk],mm[i-1][j][k]+mm[1][k][kk]);
                }
    }
    while(r--){
        int s,t;
        scanf("%d%d%d",&s,&t,&k);
        printf("%d\n",mm[min(k+1,60)][s][t]);
    }
    return 0;
}