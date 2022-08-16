#include<stdio.h>
int main(){
    int n,m,c=0,d=0;
    scanf("%d %d",&n,&m);
    int a[n],b[m];
    for(int i=1;i<=n;i++) scanf("%d",&a[n-i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[m-i]);
    for(int i=0;i<n;i++){
        if(d<m&&a[i]<=b[d])d++;
        else c++;
    }
    printf("%d",c);
}