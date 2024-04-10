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
using namespace std;
char s[16][16];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int i,j,k,n,m,an=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(s[i][j]=='W'){
                for(k=0;k<4;k++)
                    if(s[i+dx[k]][j+dy[k]]=='P')break;
                if(k<4)an++;
            }
        }
    printf("%d\n",an);
    return 0;
}