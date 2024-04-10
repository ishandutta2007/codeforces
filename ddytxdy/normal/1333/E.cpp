#include<bits/stdc++.h>
using namespace std;
const int N=520;
int n,a[N][N],t;
int main(){
    scanf("%d",&n);if(n<3)puts("-1"),exit(0);
    a[1][1]=++t;a[n][n]=n*n;
    if(n&1){
        for(int i=2;i<=n;i++){
            if(i&1)for(int j=n-1;j;j--)a[i][j]=++t;
            else for(int j=1;j<n;j++)a[i][j]=++t;
        }
    }
    else{
        for(int i=1;i<n;i++)a[2][i]=++t;
        for(int i=n-1;i;i--){
            if((n-i)&1)for(int j=3;j<=n;j++)a[j][i]=++t;
            else for(int j=n;j>=3;j--)a[j][i]=++t;
        }
    }
    for(int i=n-1;i;i--)a[i][n]=++t;
    for(int i=n-1;i>1;i--)a[1][i]=++t;
    for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
    return 0;
}