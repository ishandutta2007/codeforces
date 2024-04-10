#include<bits/stdc++.h>
using namespace std;
int main()
{
 
  long int n,v,i,j,sample,mini,k=0;
  cin>>n>>v;
  long int a[n][50],z[n];
  for(i=0;i<n;i++)
  {
      cin>>sample;
      for(j=0;j<sample;j++)
      {
          cin>>a[i][j];
          if(j==0)
          mini=a[i][0];
          else mini=min(mini,a[i][j]);
      }
      if(v>mini)
      {
         z[k++]=i+1;
      }
  }
  cout<<k<<"\n";
  for(i=0;i<k;i++)
  {
      cout<<z[i]<<" ";
  }
    return 0; 
}