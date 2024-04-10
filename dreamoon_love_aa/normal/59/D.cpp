#include<stdio.h>
#define SIZE 100000
int a[SIZE*3],d[SIZE][3];
bool used[SIZE*3];
main(){
    int n,i,j,k,me,first=1,ma=0,x;
    scanf("%d",&n);
    for(i=0;i<n*3;i++){
        scanf("%d",&x);
        a[x-1]=i;
    }
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)scanf("%d",&d[i][j]),d[i][j]--;
    scanf("%d",&me);
    me--;
    for(i=0;i<n;i++){
        for(j=0;j<3;j++)
            if(a[d[i][j]]<a[me])break;
        if(j<3)
            for(j=0;j<3;j++)used[d[i][j]]=1;
        for(j=0;j<3;j++)
            if(d[i][j]==me){
                for(k=0;k<3;k++){
                    if(d[i][k]==me)continue;
                    if(ma<d[i][k])ma=d[i][k];
                    used[d[i][k]]=1;
                }
            }
    }
    if(used[me]){
        me++;
        for(i=1;i<=3*n;i++){
            if(i!=me){
                if(!first)putchar(' ');
                else first=0;
                printf("%d",i);
            }
        }
        puts("");
    }
    else{
        for(i=0;i<=ma;i++)
            if(used[i]&&i!=me){
                if(!first)putchar(' ');
                else first=0;
                printf("%d",i+1);
            }
        for(i=0;i<=ma;i++){
            if(!used[i]&&i!=me){
                printf(" %d",i+1);
            }
        }
        for(i=ma+1;i<3*n;i++){
            if(i==me)continue;
            printf(" %d",i+1);
        }
        puts("");
    }
}