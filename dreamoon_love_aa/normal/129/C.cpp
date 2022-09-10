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
#define SIZE 1000
using namespace std;
char s[9][12];
int x[SIZE],y[SIZE],v[SIZE];
int dx[9]={1,0,-1,0,1,1,-1,-1,0};
int dy[9]={0,1,0,-1,1,-1,1,-1,0};
bool Out(int x,int y){
    return x<=0||y<=0||x>8||y>8;
}
int used[100][9][9];
int main(){
    int i,j,k;
    for(i=1;i<=8;i++)scanf("%s",s[i]+1);
    x[0]=8,y[0]=1,v[0]=0;
    for(i=0,j=1;i<j;i++){
        if(x[i]==1&&y[i]==8)break;
        for(k=0;k<9;k++){
            int nx=x[i]+dx[k];
            int ny=y[i]+dy[k];
            if(Out(nx,ny))continue;
            if(used[v[i]+1][nx][ny])continue;
            if(!Out(nx-v[i],ny)){
                if(s[nx-v[i]][ny]=='S')continue;
            }
            if(!Out(nx-v[i]-1,ny)){
                if(s[nx-v[i]-1][ny]=='S')continue;
            }
            used[v[i]+1][nx][ny]=1;
            x[j]=nx,y[j]=ny,v[j]=v[i]+1;
            j++;
        }
    }
    puts(i<j?"WIN":"LOSE");
    return 0;
}