#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int n,k;
int can[3][115];
char s[3][115];
int check(char a)
{
    return a>='A'&&a<='Z';
}
int dfs(int x,int y)
{
    if(x>=3||x<0) return 0;
    if(check(s[x][y])||check(s[x][y+1])||check(s[x][y+2])||check(s[x][y+3])) return 0;
    if(y>n-1) return can[x][y]=1;
    if(can[x][y]!=-1) return can[x][y];
    if(dfs(x-1,y+3)) return can[x][y]=1;
    if(dfs(x,y+3)) return can[x][y]=1;
    if(dfs(x+1,y+3)) return can[x][y]=1;
    return can[x][y]=0;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(can,-1,sizeof(can));
        memset(s,0,sizeof(s));
        cin>>n>>k;
        for(int i=0;i<3;i++) scanf("%s",s[i]);
        if(s[0][0]=='s')
        {
            if(check(s[0][1])) printf("NO\n");
            else if(dfs(0,1)||dfs(1,1)) printf("YES\n");
            else printf("NO\n");
        }
        if(s[1][0]=='s')
        {
            if(check(s[1][1])) printf("NO\n");
            else if(dfs(1,1)||dfs(2,1)||dfs(0,1)) printf("YES\n");
            else printf("NO\n");
        }
        if(s[2][0]=='s')
        {
            if(check(s[2][1])) printf("NO\n");
            else if(dfs(1,1)||dfs(2,1)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}