#include<stdio.h>
int main(){
    int n,m,e=0;
    scanf("%d %d\n",&n,&m);
    char a[n][m];
    for(int i=0;i<n;i++) scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                int c=0;
                if(i>0&&a[i-1][j]=='P')c++;
                if(j>0&&a[i][j-1]=='P')c++;
                if(i<n-1&&a[i+1][j]=='P')c++;
                if(j<m-1&&a[i][j+1]=='P')c++;
                if(c>0)e++;
            }
        }
    printf("%d",e);
}