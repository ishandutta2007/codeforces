#include<stdio.h>
#define SIZE 5012
char a[SIZE][SIZE];
int d[SIZE][SIZE];
bool test(int x,int r,int left,int right){
    if(left>=right)return 0;
    int now1=left,now2=right;
    for(int i=left;i<=right;i++){
        if(a[x][d[r][i]]=='0')d[r+1][now1++]=d[r][i];
        else d[r+1][now2--]=d[r][i];
    }
    for(int i=left;i<now1;i++)
        for(int j=now1;j<=right;j++){
            if(a[d[r+1][j]][d[r+1][i]]=='1'){
                printf("%d %d %d\n",x+1,d[r+1][j]+1,d[r+1][i]+1);
                return 1;
            }
        }
    if(test(d[r+1][left],r+1,left+1,now1-1))return 1;
    if(test(d[r+1][now1],r+1,now1+1,right))return 1;
    return 0;
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<n;i++)d[0][i]=i;
    if(!test(0,0,1,n-1))puts("-1");
}