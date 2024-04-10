#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int check[105]={0};
int card[105][105];
int cou[105][105]={0};
int num[105]={0},du[105];
int main()
{
    int n,m[105];
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
      scanf("%d",&m[i]);
      for(j=1;j<=m[i];j++)
      {
        scanf("%d",&card[i][j]);
        check[card[i][j]]++;
        num[card[i][j]]++;
        cou[card[i][j]][num[card[i][j]]]=i;
      }
    }
    bool flag;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        du[j]=m[j];
      flag=false;
      for(j=1;j<=m[i];j++)
      {
          for(k=1;k<=num[card[i][j]];k++)
            du[cou[card[i][j]][k]]--;
      }
      for(j=1;j<=n;j++)
      {
        if(du[j]==0&&j!=i)
        {
            printf("NO\n");
            flag=true;
            break;
        }
      }
      if(!flag)
        printf("YES\n");
    }
    return 0;
}