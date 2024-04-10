#include<stdio.h>
#include<algorithm>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
main(){
    char s[312][312];
    int n,m,order,i,j,k,h,r;
    scanf("%d%d%d",&n,&m,&order);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    h=(std::min(n,m)-1)>>1;
    for(k=1;k<=h;k++){
        for(i=k;i+k<n;i++){
            for(j=k;j+k<m;j++){
                if(s[i][j]!='*')continue;
                for(r=0;r<4;r++)
                    if(s[i+dx[r]*k][j+dy[r]*k]!='*')break;
                if(r==4){
                    order--;
                    if(order==0)break;
                }
            }
            if(j+k<m)break;
        }
        if(i+k<n)break;
    }
    if(order>0)puts("-1");
    else{
        i++;
        j++;
        printf("%d %d\n",i,j);
        printf("%d %d\n",i-k,j);
        printf("%d %d\n",i+k,j);
        printf("%d %d\n",i,j-k);
        printf("%d %d\n",i,j+k);
    }
}