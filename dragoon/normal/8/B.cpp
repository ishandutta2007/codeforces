#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <utility>
#include<stack>
using namespace std;

typedef pair<int,int> PII;

//typedef __int64 LL;
//typedef long long LL;

#define MAX(A,B) ((A) > (B) ? (A) : (B))
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define ABS(X) ((X) > 0 ? (X) : (-(X)))
#define S(X) ((X)*(X))

int m[500][500];
int vis[500][500];
char s[200];
PII X;
queue<PII> Q;

int main()
{
    int i,len,x,y;

    x=105;
    y=105;

    scanf("%s",s);

    len=strlen(s);

    m[x][y]=1;

    for(i=0;i<len;i++)
    {
        if(s[i]=='U') y++;
        else if(s[i]=='D') y--;
        else if(s[i]=='L') x--;
        else x++;

        m[x][y]=1;
    }

    int a,b;

    a=x;
    b=y;

    Q.push(PII(105,105));
    while(!Q.empty())
    {
        X=Q.front();
        Q.pop();

        x=X.first;
        y=X.second;

        if(m[x-1][y] && !vis[x-1][y]) {Q.push(PII(x-1,y)); vis[x-1][y]=vis[x][y]+1;}
        if(m[x+1][y] && !vis[x+1][y]) {Q.push(PII(x+1,y)); vis[x+1][y]=vis[x][y]+1;}
        if(m[x][y-1] && !vis[x][y-1]) {Q.push(PII(x,y-1)); vis[x][y-1]=vis[x][y]+1;}
        if(m[x][y+1] && !vis[x][y+1]) {Q.push(PII(x,y+1)); vis[x][y+1]=vis[x][y]+1;}
    }

    if(len!=vis[a][b]) 
    {
        printf("BUG\n");
    }
    else
        printf("OK\n");
    return 0;


}