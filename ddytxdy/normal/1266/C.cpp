#include<bits/stdc++.h>
using namespace std;
const int N=520;
int n,m,a[N][N];
int main(){
    scanf("%d%d",&n,&m);
    if(n==1&&m==1)puts("0"),exit(0);
    if(n<m)for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",i*(j+n));
    else for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",(i+m)*j);
    return 0;
}