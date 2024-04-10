#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m;
char s[205][205];
int bx[205][205],by[205][205];
bool judge(int x,int y,int a,char k)
{
  int i;
  if(s[x+a][y-1]==k||s[x-1][y+a]==k)return false;
  for(i=0;i<=a;i++)
  {
    if(s[x+a][y+i]!='\0'||s[x+i][y+a]!='\0')return false;
    if(s[x+a+1][y+i]==k||s[x+i][y+a+1]==k)return false;
  }
  return true;
}
bool cols(int x,int y,int a,char k)
{
  int i;
  for(i=0;i<=a;i++)
  {
    s[x+a][y+i]=s[x+i][y+a]=k;
    bx[x+a][y+i]=bx[x+i][y+a]=x;
    by[x+a][y+i]=by[x+i][y+a]=y;
  }
}
void work(int i,int j)
{
  if(i>n)return;
  if(s[i][j]!='\0')
  {
    j++;
    if(j>m)i++,j=1;
    work(i,j);
    return;
  }
  char k;
  for(k='A';k<='Z';k++)
  {
    if(s[i][j-1]==k)
    {
      if(judge(bx[i][j-1],by[i][j-1],j-by[i][j-1],k))
      {
        cols(bx[i][j-1],by[i][j-1],j-by[i][j-1],k);
        j++;
        if(j>m)i++,j=1;
        work(i,j);
        return;
      }
    }
    else if(s[i-1][j]==k)
    {
      if(judge(bx[i-1][j],by[i-1][j],i-bx[i-1][j],k))
      {
        cols(bx[i-1][j],by[i-1][j],i-bx[i-1][j],k);
        j++;
        if(j>m)i++,j=1;
        work(i,j);
        return;
      }
    }
    else
    {
      if(s[i+1][j]!=k&&s[i][j+1]!=k)
      {
        s[i][j]=k;
        bx[i][j]=i;
        by[i][j]=j;
        j++;
        if(j>m)i++,j=1;
        work(i,j);
        return;
      }
    }
  }
}
int main()
{
  cin>>n>>m;
  int i,j;
  for(j=0;j<=m+1;j++)
    s[0][j]=s[n+1][j]=' ';
  for(i=0;i<=n+1;i++)
    s[i][0]=s[i][m+1]=' ';
  work(1,1);
  for(i=1;i<=n;i++)
    puts(s[i]+1);
  return 0;
}