#include<stdio.h>
#define SIZE 32
char s[SIZE][SIZE];
bool Test(int x,int y,int xx,int yy,int dx,int dy){
    int i,j;
    for(i=0;i<dx;i++){
        for(j=0;j<dy;j++)
            if(s[x+i][y+j]!=s[xx+i][yy+j])break;
        if(j<dy)break;
    }
    if(i==dx)return 0;
    for(i=0;i<dx;i++){
        for(j=0;j<dy;j++)
            if(s[x+dx-i-1][y+dy-j-1]!=s[xx+i][yy+j])break;
        if(j<dy)break;
    }
    if(i==dx)return 0;
    if(dx==dy){
        for(i=0;i<dx;i++){
            for(j=0;j<dy;j++)
                if(s[x+j][y+dx-i-1]!=s[xx+i][yy+j])break;
            if(j<dy)break;
        }
        if(i==dx)return 0;
        for(i=0;i<dx;i++){
            for(j=0;j<dy;j++)
                if(s[x+dx-j-1][y+i]!=s[xx+i][yy+j])break;
            if(j<dy)break;
        }
        if(i==dx)return 0;
    }
    return 1;
}
bool f(int x,int y,int n,int m){
    int i,j,k,l;
    for(i=0;i<n;i+=x)
        for(j=0;j<m;j+=y)
            for(k=0;k<n;k+=x)
                for(l=0;l<m;l+=y){
                    if(i==k&&j==l)continue;
                    if(!Test(i,j,k,l,x,y))return 0;
                }
    return 1;
}
main(){
    int n,m,i,j,an1=0,an2,an3,mi=10000;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=1;i<=n;i++){
        if(n%i)continue;
        for(j=1;j<=m;j++){
            if(m%j)continue;
            if(f(i,j,n,m)){
                an1++;
                if(i*j<mi){
                    mi=i*j;
                    an2=i;
                    an3=j;
                }
            }
        }
    }
    printf("%d\n%d %d\n",an1,an2,an3);
}