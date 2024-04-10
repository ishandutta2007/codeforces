#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int d[m];
    for(int i=0;i<m;i++){
        scanf("%d",&d[i]);
        if(d[i]==1||d[i]==n)goto no;
    }
    for(int i=0;i<m-1;i++)
        for(int j=0;j<m-1-i;j++)
            if(d[j]>d[j+1]){
                int t=d[j];
                d[j]=d[j+1];
                d[j+1]=t;
            }
    for(int i=0;i<m-2;i++)
        if((d[i+1]==d[i]+1)&&(d[i+2]==d[i]+2))goto no;
    printf("YES");
    return 0;
    no: printf("NO");
}