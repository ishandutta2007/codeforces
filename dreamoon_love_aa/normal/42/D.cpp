#include<stdio.h>
bool used[4001],used2[1200];
int a[20],an[20][20];
main(){
    int i,j,k,n;
    a[0]=1;
    a[1]=2;
    used[3]=1;
    scanf("%d",&n);
    for(i=2;i<n-1;i++){
        for(j=a[i-1]+1;;j++){
            for(k=0;k<i;k++)
                if(used[a[k]+j])break;
            if(k==i){
                a[i]=j;
                for(k=0;k<i;k++)used[a[k]+j]=1;
                used2[j]=1;
                break;
            }
        }
    }
    for(i=1;i<n;i++)an[0][i]=an[i][0]=a[i-1];
    for(i=0;;i++){
        for(j=1;j<n;j++){
            for(k=j+1;k<n;k++)
                if(used2[an[0][j]+an[0][k]+i])break;
            if(k<n)break;
        }
        if(j==n)break;
    }
    k=i;
    for(i=1;i<n;i++)
        for(j=i+1;j<n;j++)
            an[i][j]=an[j][i]=k+an[0][i]+an[0][j];
    for(i=0;i<n;i++,puts(""))
        for(j=0;j<n;j++){
            if(j)putchar(' ');
            printf("%d",an[i][j]);
        }
}