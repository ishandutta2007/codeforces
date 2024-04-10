#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

//typedef __int64 LL;
//#define I64d "%I64d"
//typedef long long LL;
//#define I64d "%lld"

int cnt;
int grid[300][300];
char word[300][300];
int CNT;

void check_adj(int rr,int cc)
{
    if(grid[rr][cc]==1)
    {
        cnt++;
        grid[rr][cc]=2;
    }
    else
        return;

    check_adj(rr+1,cc);
    check_adj(rr-1,cc);
    check_adj(rr+1,cc+1);
    check_adj(rr+1,cc-1);
    check_adj(rr-1,cc+1);
    check_adj(rr-1,cc-1);
    check_adj(rr,cc+1);
    check_adj(rr,cc-1);
}

void check_adj1(int rr,int cc)
{
    if(grid[rr][cc]==2)
    {
        cnt++;
        grid[rr][cc]=1;
    }
    else
        return;

    check_adj1(rr+1,cc);
    check_adj1(rr-1,cc);
    check_adj1(rr+1,cc+1);
    check_adj1(rr+1,cc-1);
    check_adj1(rr-1,cc+1);
    check_adj1(rr-1,cc-1);
    check_adj1(rr,cc+1);
    check_adj1(rr,cc-1);
}


void check_rect(int rr,int cc)
{
    int r,c;

    cnt=0;
    r=rr;
    c=cc;

    while(grid[r][c+cnt]==1)
    {
//      grid[r][c+cnt]=2;
        cnt++;
    }

    c+=cnt-1;

    int Z = cnt;

    cnt=0;
    while(grid[r+cnt][c]==1)
    {
//      grid[r+cnt][c]=2;
        cnt++;
    }
    
    if(Z!=cnt) goto end;

    r+=cnt-1;

    cnt=0;
    while(grid[r][c-cnt]==1)
    {
//      grid[r][c-cnt]=2;
        cnt++;
    }
    
    c-=cnt-1;

    if(Z!=cnt) goto end;

    cnt=0;
    while(grid[r-cnt][c]==1)
    {
//      grid[r-cnt][c]=2;
        cnt++;
    }
    
    r-=cnt-1;

    if(Z!=cnt) goto end;

    cnt=0;
    check_adj(rr,cc);

    if(cnt!=(Z)*4-4) goto end;
    if(cnt==1) goto end;

    CNT++;
    return;

end:
    r=r;
    check_adj(rr,cc);
}

void check_dia(int rr,int cc)
{
    int r,c,Z;

    cnt=0;
    r=rr;
    c=cc;

    while(grid[r+cnt][c+cnt]==2)
    {
//      grid[r][c+cnt]=2;
        cnt++;
    }

    Z=cnt;

    c+=cnt-1;
    r+=cnt-1;

    cnt=0;
    while(grid[r+cnt][c-cnt]==2)
    {
//      grid[r+cnt][c]=2;
        cnt++;
    }
    
    if(Z!=cnt) goto end;

    r+=cnt-1;
    c-=cnt-1;

    cnt=0;
    while(grid[r-cnt][c-cnt]==2)
    {
//      grid[r][c-cnt]=2;
        cnt++;
    }
    
    c-=cnt-1;
    r-=cnt-1;

    if(Z!=cnt) goto end;

    cnt=0;
    while(grid[r-cnt][c+cnt]==2)
    {
//      grid[r-cnt][c]=2;
        cnt++;
    }
    
    r-=cnt-1;
    c+=cnt-1;

    if(Z!=cnt) goto end;

    cnt=0;
    check_adj1(rr,cc);

    if(cnt!=(Z)*4-4) goto end;
    if(cnt==1) goto end;

    CNT++;

    return;
end:
    r=r;
    check_adj1(rr,cc);
}

int main() 
{
    int T,r,c,i,j;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&r,&c);

        for(i=0;i<r;i++) scanf("%s",word[i]);

        for(i=0;i<=r+1;i++)
            for(j=0;j<=c+1;j++)
                grid[i][j]=0;

        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            {
                grid[i][j]=word[i-1][j-1]=='1';
//              grid[i][j]=grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + grid[i][j];
            }

        CNT=0;

        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(grid[i][j]==1)
                {
                    check_rect(i,j);
                }

        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(grid[i][j]==2)
                    check_dia(i,j);

        printf("%d\n",CNT);
    }


    return 0;
}