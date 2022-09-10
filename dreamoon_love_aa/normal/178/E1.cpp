#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 2000
int a[SIZE][SIZE],n;
int dx[8]={1,-1,0,0,-1,1,1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
int xx[4]{1,0,1,2};
int yy[4]={0,1,2,1};
struct Point{
    int x,y;
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
};
int cnt;
int ha[4][2];
bool Out(int x,int y){return x<0||y<0||x>=n||y>=n;}
void dfs(int x,int y){
    a[x][y]=0;
    for(int i=0;i<4;i++){
        ha[i][0]=min(ha[i][0],x*xx[i]+y*yy[i]);
        ha[i][1]=max(ha[i][1],x*xx[i]+y*yy[i]);
    }
    cnt++;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(Out(nx,ny))continue;
        if(a[nx][ny])dfs(nx,ny);
    }
}
int main(){
    int i,j,k,an1=0,an2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(a[i][j]){
                for(k=0;k<4;k++){
                    ha[k][0]=100000000;
                    ha[k][1]=-100000000;
                }
                dfs(i,j);
                int tmp=(int)(sqrt(cnt)+1e-12);
                double v[8];
                //puts("get");
                for(k=0;k<4;k++)v[k]=ha[k][1]-ha[k][0];
                v[0]*=sqrt(5);
                v[1]*=sqrt(5);
                sort(v,v+4);
                if(v[0]*1.1>=v[3])an1++;
                else an2++;

            }
        }
    printf("%d %d\n",an1,an2);
    return 0;
}