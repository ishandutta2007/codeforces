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
char s[111][111];
int x[3],y[3],xn,yyn;
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(s[i][j]=='*'){
                x[xn++]=i;
                y[yyn++]=j;
            }
    sort(x,x+xn);
    sort(y,y+yyn);
    printf("%d %d\n",x[0]+x[2]-x[1],y[0]+y[2]-y[1]);
    return 0;
}