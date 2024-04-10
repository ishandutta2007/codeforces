#include<stdio.h>
int d[128];
main(){
    char s[64];
    int t,m,x,n=1,i,j;
    scanf("%d%d",&t,&m);
    while(t--){
        scanf("%s",s);
        if(s[0]=='a'){
            scanf("%d",&x);
            for(i=1;i+x-1<=m;i++){
                for(j=0;j<x;j++)
                    if(d[i+j])break;
                if(j==x)break;
            }
            if(i+x-1>m)puts("NULL");
            else{
                printf("%d\n",n);
                for(j=0;j<x;j++)d[i+j]=n;
                n++;
            }
        }
        else if(s[0]=='e'){
            scanf("%d",&x);
            j=0;
            for(i=1;i<=m;i++){
                if(d[i]==x){
                    d[i]=0;
                    j=1;
                }
            }
            if(j==0||x==0)puts("ILLEGAL_ERASE_ARGUMENT");
        }
        else{
            for(i=j=1;i<=m;i++)
                if(d[i])d[j++]=d[i];
            for(;j<=m;j++)d[j]=0;
        }
    }
}