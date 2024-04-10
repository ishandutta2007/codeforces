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

char grid[200][200];
char col[100];
int R,C,i,j,d;
int ni,nj,cnt;
int color[100];

int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};

int main()
{
    scanf("%d%d%s",&R,&C,col);
    for(i=0;i<R;i++) scanf("%s",grid[i]);

    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
            if(grid[i][j]==col[0])
            {
                for(d=0;d<4;d++)
                {
                    ni=i+di[d];
                    nj=j+dj[d];

                    if(ni<0 || ni>=R || nj<0 || nj>=C || grid[ni][nj]==col[0]|| grid[ni][nj]=='.') continue;
                    color[ grid[ni][nj]-'A' ] = 1;
                }
            }

    cnt=0;
    for(i=0;i<26;i++)
        cnt+=color[i];

    printf("%d\n",cnt);

    return 0;
}