#include<stdio.h>
int main(){
    int n,m,k,t,c=0;
    scanf("%d %d %d",&n,&m,&k);
    int a[m+1][n];
    for(int i=0;i<=m;i++){
        scanf("%d",&t);
        for(int j=0;j<n;j++){
            a[i][j]=t%2;
            t/=2;
        }
    }
    for(int i=0;i<m;i++){
        t=0;
        for(int j=0;j<n;j++){
            t+=a[i][j]^a[m][j];
        }
        if(t<=k)c++;
    }
    printf("%d",c);
}