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
char s[55][55];
int n,m,cs,used[55][55];
void find(int& x,int& y){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='#'){
                x=i,y=j;
                return;
            }
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y){
    if(x<0||y<0||x>=n||y>=m||used[x][y]==cs||s[x][y]!='#')return;
    used[x][y]=cs;
    for(int i=0;i<4;i++)
        dfs(x+dx[i],y+dy[i]);

}
bool test(){
    int i,j,cnt=0;
    cs++;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='.')continue;
            if(used[i][j]==cs)continue;
            cnt++;
            if(cnt>1)return 1;
            dfs(i,j);
        }
    return 0;
}
int main(){
    int i,j,k,all=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(s[i][j]=='#')all++;
    if(all<=2){
        puts("-1");
        return 0;
    }
    int x,y;
    find(x,y);
    if(s[x+1][y]!='#'||s[x][y+1]!='#'){
        puts("1");
        return 0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='#'){
                s[i][j]='.';
                if(test()){
                    puts("1");
                    return 0;
                }
                s[i][j]='#';
            }
        }
    puts("2");
    return 0;
}