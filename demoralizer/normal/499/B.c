#include<stdio.h>
#include<string.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char a[m][12],t[12],b[m][12];int u[m];
    for(int i=0;i<m;i++){
        scanf("%s %s",a[i],b[i]);
        u[i]=0;
        if(strlen(b[i])<strlen(a[i]))u[i]=1;
    }
    for(int i=0;i<n;i++){
        scanf("%s",t);
        int j=0;
        while(strcmp(t,a[j])!=0)j++;
        if(u[j])printf("%s ",b[j]);
        else printf("%s ",t);
    }
}