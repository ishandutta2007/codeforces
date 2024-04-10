#include<stdio.h>
#define SIZE 1024
char s[SIZE][SIZE];
int dp1[SIZE][SIZE],dp2[SIZE][SIZE],n,m;
struct data{
    // type=0 north, type=1 west;
    int type,sx,sy,ex,ey;
}a[100000];
bool Out(int x,int y){return x<=0||y<=0||x>n||y>m;}
int xx[26],yy[26];
main(){
    int i,j,K,x,y,nx,ny,an=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<26;i++)
        xx[i]=yy[i]=-1;
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(s[i][j]=='#'){
                dp1[i][j]=dp1[i][j-1]+1;
                dp2[i][j]=dp2[i-1][j]+1;
            }
            else{
                dp1[i][j]=dp1[i][j-1];
                dp2[i][j]=dp2[i-1][j];
                if(s[i][j]>='A'&&s[i][j]<='Z'){
                    xx[s[i][j]-'A']=i;
                    yy[s[i][j]-'A']=j;
                }
            }
        }
    scanf("%d",&K);
    x=y=0;
    int step,tt;
    char c[4];
    for(i=0;i<K;i++){
        scanf("%s%d",c,&step);
        if(c[0]=='N'){
            tt=0;
            nx=x-step;
            ny=y;
        }
        else if(c[0]=='S'){
            tt=0;
            nx=x+step;
            ny=y;
        }
        else if(c[0]=='W'){
            tt=1;
            nx=x;
            ny=y-step;
        }
        else if(c[0]=='E'){
            tt=1;
            nx=x;
            ny=y+step;
        }
        if(nx<x||ny<y){
            a[i]=(data){tt,nx,ny,x,y};
        }
        else{
            a[i]=(data){tt,x,y,nx,ny};
        }
        x=nx,y=ny;
    }
    for(i=0;i<26;i++){
        if(xx[i]==-1)continue;
        for(j=0;j<K;j++){
            if(Out(xx[i]+a[j].sx,yy[i]+a[j].sy)||Out(xx[i]+a[j].ex,yy[i]+a[j].ey))break;
            if(a[j].type==0){
                if(dp2[xx[i]+a[j].ex][yy[i]+a[j].ey]-dp2[xx[i]+a[j].sx-1][yy[i]+a[j].sy])break;
            }
            else{
                if(dp1[xx[i]+a[j].ex][yy[i]+a[j].ey]-dp1[xx[i]+a[j].sx][yy[i]+a[j].sy-1])break;
            
            }
        }
        if(j==K){
            putchar('A'+i);
            an=1;
        }        
    }
    if(!an)printf("no solution");
    puts("");
}