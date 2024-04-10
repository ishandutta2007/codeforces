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
int n,m,an;
char s[10][12],res[10][12];
int pp[4][5][2]={{{0,0},{0,1},{0,2},{1,1},{2,1}},
                 {{0,1},{1,1},{2,0},{2,1},{2,2}},
                 {{0,0},{1,0},{1,1},{1,2},{2,0}},
                 {{0,2},{1,0},{1,1},{1,2},{2,2}}};
void dfs(int x,int y,int v){
    if(v+(n*m-x*m-y)/6<=an)return;
    if(x+2==n){
        if(v>an){
            an=v;
            memcpy(res,s,120);
        }
        return;
    }
    if(y+2==m){
        dfs(x+1,0,v);
        return;
    }
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<5;j++)
            if(s[x+pp[i][j][0]][y+pp[i][j][1]]!='.')break;
        if(j==5){
            for(j=0;j<5;j++)
                s[x+pp[i][j][0]][y+pp[i][j][1]]='A'+v;
            dfs(x,y+1,v+1);
            for(j=0;j<5;j++)
                s[x+pp[i][j][0]][y+pp[i][j][1]]='.';
        }
    }
    dfs(x,y+1,v);
}
int main(){
    int i,j,k;
    cin>>n>>m;
    if(n<3||m<3){
        puts("0");
        for(i=0;i<n;i++,puts(""))
            for(j=0;j<m;j++)putchar('.');
    }
    else{
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)s[i][j]='.';
        dfs(0,0,0);
        printf("%d\n",an);
        for(i=0;i<n;i++)puts(res[i]);
    }
    return 0;
}