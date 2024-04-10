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

int X[30],Y[30];
int n;
int dp[1<<24];
int F,x,y;
int w[30][30];

int DP(int mask)
{
    if(mask == F)
        return 0;

    if(dp[mask]) return dp[mask];

    int i,j,cost;

    for(i=0;i<n;i++) if(mask & (1<<i)) ; else break;

    dp[mask] = DP(mask | (1<<i)) + w[n][i]*2;

    for(j=i+1;j<n;j++)
        if(!(mask & (1<<j)))
        {
            cost = w[n][i]+w[n][j]+w[i][j]+DP(mask | (1<<i) | (1<<j));

            if(dp[mask]==0 || dp[mask]>cost) dp[mask]=cost;
        }

    return dp[mask];
}

void PDP(int mask)
{
    if(mask == F)
        return;

    int i,j;

    for(i=0;i<n;i++) if(mask & (1<<i)) ; else break;

    if(dp[mask]==dp[mask|(1<<i)]+w[n][i]*2)
    {
        printf(" %d 0",i+1);
        PDP(mask | (1<<i));
        return;
    }

    for(j=i+1;j<n;j++)
        if(!(mask & (1<<j)))
        {
            if(dp[mask] == w[n][i]+w[n][j]+w[i][j]+dp[mask | (1<<i) | (1<<j)])
            {
                printf(" %d %d 0",i+1,j+1);
                PDP(mask | (1<<i) | (1<<j));
                return;
            }
        }

}

int main()
{
    int i,ans,cost,j;
    ans = -1;

    scanf("%d%d",&x,&y);

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&X[i],&Y[i]);

    F=(1<<n)-1;
    for(i=0;i<n;i++)
        w[n][i]=S(x-X[i])+S(y-Y[i]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            w[i][j]=S(X[j]-X[i])+S(Y[j]-Y[i]);

    int id;
    if(n&1)
    {
        for(i=0;i<n;i++)
        {
            cost = 2*w[n][i]+DP(1<<i);
            if(ans > cost || ans==-1)
                id=i, ans = cost;
        }

        printf("%d\n",ans);
        printf("0 %d 0",id+1);
        PDP(1<<id);
        printf("\n");
    }
    else
    {
        ans = DP(0);
        printf("%d\n",ans);
        printf("0");
        PDP(0);
        printf("\n");
    }


    return 0;
}