#include<bits/stdc++.h>
using namespace std;
int main()
{
 
  int r,c,rn=0,cn=0,i,j,flag;
  cin>>r>>c;
  char a[r][c];
  for(i=0;i<r;i++)
  {
      for(j=0;j<c;j++)
      cin>>a[i][j];
  }
  for(i=0;i<r;i++)
  {
      flag=0;
      for(j=0;j<c;j++)
      {
          if(a[i][j]=='S')
          {
              flag=1;
              break;
          }
      }
      if(flag==0) rn++;
  }
  for(i=0;i<c;i++)
  {
      flag=0;
      for(j=0;j<r;j++)
      {
          if(a[j][i]!='.')
          {
              flag=1;
          }
      }
      if(flag==0) cn++;
  }
  cout<<rn*c+cn*r-rn*cn;
    return 0; 
}