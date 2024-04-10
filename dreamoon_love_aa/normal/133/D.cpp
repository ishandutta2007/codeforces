#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#define SIZE 100000
using namespace std;
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int x[SIZE],y[SIZE],DP[SIZE],CP[SIZE],R,C,used[50][50][4][4];
char s[64][64];
bool Out(int xx,int yy){return xx<0||yy<0||xx>=R||yy>=C;}
void next(int x1,int y1,int DP1,int CP1,int &x2,int &y2,int &DP2,int &CP2){
    int i;
    for(i=1;;i++){
        int nx=x1+dx[DP1]*i;
        int ny=y1+dy[DP1]*i;
        if(Out(nx,ny)||s[nx][ny]!=s[x1][y1])break;
    }
    i--;
    x1+=dx[DP1]*i;
    y1+=dy[DP1]*i;
    for(i=1;;i++){
        int nx=x1+dx[(DP1+CP1)&3]*i;
        int ny=y1+dy[(DP1+CP1)&3]*i;
        if(Out(nx,ny)||s[nx][ny]!=s[x1][y1])break;
    }
    i--;
    x1+=dx[(DP1+CP1)&3]*i;
    y1+=dy[(DP1+CP1)&3]*i;
    int nx=x1+dx[DP1];
    int ny=y1+dy[DP1];
    //printf("%d,%d[%d,%d]:%d,%d\n",R,C,nx,ny,(int)Out(nx,ny),(int)s[nx][ny]);
    if(Out(nx,ny)||!s[nx][ny]){
        x2=x1;
        y2=y1;
        if(CP1==1){
            CP2=3;
            DP2=DP1;
        }
        else{
            CP2=1;
            DP2=(DP1+3)&3;
        }
    }
    else{
        x2=nx;
        y2=ny;
        DP2=DP1;
        CP2=CP1;
    }
}
int main(){
    int i,j,k,m;
    scanf("%d%d",&R,&m);
    for(i=0;i<R;i++)
        scanf("%s",s[i]);
    C=strlen(s[0]);
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)s[i][j]-='0';
    CP[0]=1;
    memset(used,-1,sizeof(used));
    used[0][0][0][1]=0;
    for(i=1;;i++){
        next(x[i-1],y[i-1],DP[i-1],CP[i-1],x[i],y[i],DP[i],CP[i]);
        if(used[x[i]][y[i]][DP[i]][CP[i]]>=0){
            break;
        }
        used[x[i]][y[i]][DP[i]][CP[i]]=i;
    }
    int tmp=used[x[i]][y[i]][DP[i]][CP[i]];
    if(m<i)printf("%d\n",(int)s[x[m]][y[m]]);
    else printf("%d\n",(int)s[x[tmp+(m-tmp)%(i-tmp)]][y[tmp+(m-tmp)%(i-tmp)]]);
    return 0;
}