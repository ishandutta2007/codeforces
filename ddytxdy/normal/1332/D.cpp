#include<bits/stdc++.h>
using namespace std;
int k,n,m,dat=131072,a[10][10];
int main(){
    scanf("%d",&k);
    puts("3 3");
    for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)a[i][j]=dat;
    a[3][1]^=dat;a[3][3]^=dat;a[1][1]|=k;a[2][1]|=k;a[3][1]|=k;a[3][2]|=k;a[3][3]|=k;
    for(int i=1;i<=3;i++,puts(""))for(int j=1;j<=3;j++)printf("%d ",a[i][j]);
    return 0;
}